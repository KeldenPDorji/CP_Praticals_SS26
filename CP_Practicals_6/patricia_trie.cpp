#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Simplified PATRICIA Trie Node - string-based for clarity
struct PatriciaNode {
    string edgeLabel;        // Label on edge from parent
    string key;              // The complete key at this node (if leaf)
    bool isEndOfWord;        // Whether this is an end node
    unordered_map<char, PatriciaNode*> children;
    
    PatriciaNode() : isEndOfWord(false) {}
};

class PATRICIATrie {
private:
    PatriciaNode* root;
    
    // Find common prefix length between two strings
    int findCommonPrefixLen(const string& s1, const string& s2) {
        int i = 0;
        while (i < s1.length() && i < s2.length() && s1[i] == s2[i]) {
            i++;
        }
        return i;
    }
    
public:
    PATRICIATrie() {
        root = new PatriciaNode();
    }
    
    // Insert a string into PATRICIA trie (simplified implementation)
    void insert(const string& key) {
        if (key.empty()) {
            cout << "Cannot insert empty string!" << endl;
            return;
        }
        
        PatriciaNode* current = root;
        string remaining = key;
        
        while (!remaining.empty()) {
            char firstChar = remaining[0];
            
            // If child doesn't exist, create it
            if (current->children.find(firstChar) == current->children.end()) {
                PatriciaNode* newNode = new PatriciaNode();
                newNode->edgeLabel = remaining;
                newNode->key = key;
                newNode->isEndOfWord = true;
                current->children[firstChar] = newNode;
                cout << "Inserted: \"" << key << "\"" << endl;
                return;
            }
            
            PatriciaNode* child = current->children[firstChar];
            int commonLen = findCommonPrefixLen(remaining, child->edgeLabel);
            
            // Perfect match - traverse deeper
            if (commonLen == child->edgeLabel.length()) {
                remaining = remaining.substr(commonLen);
                current = child;
                
                // If we've consumed all characters
                if (remaining.empty()) {
                    if (child->isEndOfWord) {
                        cout << "Key already exists!" << endl;
                    } else {
                        child->isEndOfWord = true;
                        cout << "Inserted: \"" << key << "\"" << endl;
                    }
                    return;
                }
                continue;
            }
            
            // Partial match - need to split the edge
            string commonPrefix = child->edgeLabel.substr(0, commonLen);
            string childSuffix = child->edgeLabel.substr(commonLen);
            remaining = remaining.substr(commonLen);
            
            // Create intermediate node
            PatriciaNode* intermediate = new PatriciaNode();
            intermediate->edgeLabel = commonPrefix;
            intermediate->isEndOfWord = false;
            
            // Reconnect old child with new suffix
            child->edgeLabel = childSuffix;
            intermediate->children[childSuffix[0]] = child;
            
            // Create new leaf if remaining is not empty
            if (!remaining.empty()) {
                PatriciaNode* newLeaf = new PatriciaNode();
                newLeaf->edgeLabel = remaining;
                newLeaf->key = key;
                newLeaf->isEndOfWord = true;
                intermediate->children[remaining[0]] = newLeaf;
            } else {
                intermediate->isEndOfWord = true;
                intermediate->key = key;
            }
            
            // Update parent's link
            current->children[firstChar] = intermediate;
            cout << "Inserted: \"" << key << "\"" << endl;
            return;
        }
    }
    
    // Search for a string
    bool search(const string& key) {
        if (key.empty()) return false;
        
        PatriciaNode* current = root;
        string remaining = key;
        
        while (!remaining.empty()) {
            char firstChar = remaining[0];
            
            if (current->children.find(firstChar) == current->children.end()) {
                return false;
            }
            
            PatriciaNode* child = current->children[firstChar];
            
            // Check if remaining string starts with edge label
            if (remaining.find(child->edgeLabel) != 0) {
                return false;
            }
            
            remaining = remaining.substr(child->edgeLabel.length());
            
            if (remaining.empty()) {
                return child->isEndOfWord;
            }
            
            current = child;
        }
        
        return false;
    }
    
    // Delete a string
    bool deleteKey(const string& key) {
        if (key.empty()) return false;
        
        PatriciaNode* current = root;
        string remaining = key;
        
        while (!remaining.empty()) {
            char firstChar = remaining[0];
            
            if (current->children.find(firstChar) == current->children.end()) {
                return false;
            }
            
            PatriciaNode* child = current->children[firstChar];
            
            if (remaining.find(child->edgeLabel) != 0) {
                return false;
            }
            
            remaining = remaining.substr(child->edgeLabel.length());
            
            if (remaining.empty()) {
                if (child->isEndOfWord) {
                    child->isEndOfWord = false;
                    cout << "Deleted: \"" << key << "\"" << endl;
                    return true;
                }
                return false;
            }
            
            current = child;
        }
        
        return false;
    }
    
    void cleanup(PatriciaNode* node) {
        if (node == nullptr) return;
        for (auto& pair : node->children) {
            cleanup(pair.second);
        }
        delete node;
    }
    
    ~PATRICIATrie() {
        cleanup(root);
    }
};

int main() {
    PATRICIATrie patricia;
    int choice;
    string word;
    
    cout << "=== PATRICIA Trie Implementation ===" << endl;
    cout << "Operations: Insert, Search, Delete" << endl << endl;
    
    while (true) {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Insert a word" << endl;
        cout << "2. Search for a word" << endl;
        cout << "3. Delete a word" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter word to insert: ";
                getline(cin, word);
                patricia.insert(word);
                break;
                
            case 2:
                cout << "Enter word to search: ";
                getline(cin, word);
                if (patricia.search(word)) {
                    cout << "\"" << word << "\" found in PATRICIA trie!" << endl;
                } else {
                    cout << "\"" << word << "\" not found in PATRICIA trie!" << endl;
                }
                break;
                
            case 3:
                cout << "Enter word to delete: ";
                getline(cin, word);
                if (patricia.deleteKey(word)) {
                    cout << "\"" << word << "\" deleted successfully!" << endl;
                } else {
                    cout << "\"" << word << "\" not found!" << endl;
                }
                break;
                
            case 4:
                cout << "Exiting..." << endl;
                return 0;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}
