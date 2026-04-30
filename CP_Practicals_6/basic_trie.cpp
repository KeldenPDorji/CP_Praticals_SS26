#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Trie Node structure
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the trie
    void insert(const string& word) {
        TrieNode* current = root;
        
        for (char ch : word) {
            // If character doesn't exist, create a new node
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        
        // Mark the end of the word
        current->isEndOfWord = true;
        cout << "Inserted: \"" << word << "\"" << endl;
    }
    
    // Search for a word in the trie
    bool search(const string& word) {
        TrieNode* current = root;
        
        for (char ch : word) {
            // If character doesn't exist, word is not in trie
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        
        // Check if the current node marks the end of a word
        return current->isEndOfWord;
    }
    
    // Helper function to find all words with a given prefix
    void findAllWordsWithPrefix(TrieNode* node, const string& prefix, vector<string>& result) {
        if (node == nullptr) return;
        
        // If current node marks the end of a word, add it to result
        if (node->isEndOfWord) {
            result.push_back(prefix);
        }
        
        // Traverse all children
        for (auto& pair : node->children) {
            findAllWordsWithPrefix(pair.second, prefix + pair.first, result);
        }
    }
    
    // Delete a word from the trie
    bool deleteWord(const string& word) {
        return deleteHelper(root, word, 0);
    }
    
private:
    // Helper function for deletion using DFS
    bool deleteHelper(TrieNode* node, const string& word, int index) {
        if (node == nullptr) {
            return false;
        }
        
        // Base case: we've reached the end of the word
        if (index == word.length()) {
            // Check if the word exists in the trie
            if (!node->isEndOfWord) {
                return false;
            }
            
            // Mark as not end of word
            node->isEndOfWord = false;
            
            // If node has no children, it can be deleted
            return node->children.empty();
        }
        
        char ch = word[index];
        TrieNode* child = nullptr;
        
        // If character doesn't exist, word doesn't exist
        if (node->children.find(ch) == node->children.end()) {
            return false;
        }
        
        child = node->children[ch];
        
        // Recursively delete the word
        bool shouldDeleteChild = deleteHelper(child, word, index + 1);
        
        // If child should be deleted, remove the reference
        if (shouldDeleteChild) {
            node->children.erase(ch);
            delete child;
            
            // Current node can be deleted if it has no children and is not end of another word
            return node->children.empty() && !node->isEndOfWord;
        }
        
        return false;
    }
};

int main() {
    Trie trie;
    int choice;
    string word;
    
    cout << "=== Basic Trie Implementation ===" << endl;
    cout << "Operations: Insert, Search, Delete" << endl << endl;
    
    while (true) {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Insert a word" << endl;
        cout << "2. Search for a word" << endl;
        cout << "3. Delete a word" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        
        cin >> choice;
        cin.ignore(); // Ignore newline after number input
        
        switch (choice) {
            case 1:
                cout << "Enter word to insert: ";
                getline(cin, word);
                trie.insert(word);
                break;
                
            case 2:
                cout << "Enter word to search: ";
                getline(cin, word);
                if (trie.search(word)) {
                    cout << "\"" << word << "\" found in trie!" << endl;
                } else {
                    cout << "\"" << word << "\" not found in trie!" << endl;
                }
                break;
                
            case 3:
                cout << "Enter word to delete: ";
                getline(cin, word);
                if (trie.deleteWord(word)) {
                    cout << "\"" << word << "\" deleted successfully!" << endl;
                } else {
                    cout << "\"" << word << "\" not found or couldn't be deleted!" << endl;
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
