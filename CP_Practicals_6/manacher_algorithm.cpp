#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ManacherAlgorithm {
private:
    // Preprocess string to handle even-length palindromes
    // e.g., "babad" becomes "#b#a#b#a#d#"
    string preprocessString(const string& s) {
        string processed = "#";
        for (char ch : s) {
            processed += ch;
            processed += "#";
        }
        return processed;
    }
    
public:
    // Find the longest palindromic substring using Manacher's Algorithm
    string findLongestPalindrome(const string& s) {
        if (s.empty()) {
            return "";
        }
        
        string processed = preprocessString(s);
        int n = processed.length();
        
        // P[i] = length of palindrome centered at i
        vector<int> P(n, 0);
        
        int center = 0;  // Center of the rightmost palindrome
        int right = 0;   // Right boundary of the rightmost palindrome
        
        int maxLen = 0;
        int centerIndex = 0;
        
        for (int i = 0; i < n; i++) {
            // Mirror of i with respect to center
            int mirror = 2 * center - i;
            
            // If i is within the right boundary, we can use previously computed values
            if (i < right) {
                P[i] = min(right - i, P[mirror]);
            }
            
            // Try to expand palindrome centered at i
            try {
                while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 &&
                       processed[i + P[i] + 1] == processed[i - P[i] - 1]) {
                    P[i]++;
                }
            } catch (...) {
                // Handle any boundary issues
            }
            
            // If palindrome centered at i extends past right, update center and right
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
            
            // Track the longest palindrome
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        
        // Extract the longest palindrome from the original string
        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }
    
    // Find all palindromic substrings
    vector<string> findAllPalindromes(const string& s) {
        vector<string> palindromes;
        
        if (s.empty()) {
            return palindromes;
        }
        
        string processed = preprocessString(s);
        int n = processed.length();
        vector<int> P(n, 0);
        
        int center = 0;
        int right = 0;
        
        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;
            
            if (i < right) {
                P[i] = min(right - i, P[mirror]);
            }
            
            try {
                while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 &&
                       processed[i + P[i] + 1] == processed[i - P[i] - 1]) {
                    P[i]++;
                }
            } catch (...) {
                // Handle any boundary issues
            }
            
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
            
            // Add palindrome if it has length > 1 (filter out single characters)
            if (P[i] > 1) {
                int start = (i - P[i]) / 2;
                int len = P[i];
                palindromes.push_back(s.substr(start, len));
            }
        }
        
        // Remove duplicates
        sort(palindromes.begin(), palindromes.end());
        palindromes.erase(unique(palindromes.begin(), palindromes.end()), palindromes.end());
        
        return palindromes;
    }
    
    // Check if a string is palindrome using Manacher's Algorithm
    bool isPalindrome(const string& s) {
        if (s.empty()) return true;
        
        string processed = preprocessString(s);
        int n = processed.length();
        vector<int> P(n, 0);
        
        int center = 0;
        int right = 0;
        
        // Only check the middle part (the original string)
        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;
            
            if (i < right) {
                P[i] = min(right - i, P[mirror]);
            }
            
            try {
                while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 &&
                       processed[i + P[i] + 1] == processed[i - P[i] - 1]) {
                    P[i]++;
                }
            } catch (...) {
                // Handle any boundary issues
            }
            
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
        }
        
        // Check if the entire processed string is a palindrome
        // The center should be at n/2 with P[n/2] = n/2
        int mid = n / 2;
        return P[mid] == mid;
    }
};

int main() {
    ManacherAlgorithm manacher;
    string choice;
    string input;
    
    cout << "=== Manacher's Algorithm Implementation ===" << endl;
    cout << "Find longest palindromic substrings efficiently in O(n) time" << endl << endl;
    
    while (true) {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Find longest palindromic substring" << endl;
        cout << "2. Find all palindromic substrings" << endl;
        cout << "3. Check if string is palindrome" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        
        getline(cin, choice);
        
        // Trim whitespace from both ends
        size_t start = choice.find_first_not_of(" \t\r\n");
        size_t end = choice.find_last_not_of(" \t\r\n");
        
        if (start == string::npos) {
            // Empty input
            cout << "Invalid choice! Please try again." << endl;
            continue;
        }
        
        choice = choice.substr(start, (end - start + 1));
        
        if (choice == "1") {
            cout << "Enter string: ";
            getline(cin, input);
            // Trim leading/trailing whitespace
            size_t start = input.find_first_not_of(" \t\r\n");
            if (start != string::npos) {
                size_t end = input.find_last_not_of(" \t\r\n");
                input = input.substr(start, (end - start + 1));
            }
            string result = manacher.findLongestPalindrome(input);
            if (result.empty()) {
                cout << "No palindrome found or empty string!" << endl;
            } else {
                cout << "Longest palindromic substring: \"" << result << "\"" << endl;
                cout << "Length: " << result.length() << endl;
            }
        }
        else if (choice == "2") {
            cout << "Enter string: ";
            getline(cin, input);
            // Trim leading/trailing whitespace
            size_t start = input.find_first_not_of(" \t\r\n");
            if (start != string::npos) {
                size_t end = input.find_last_not_of(" \t\r\n");
                input = input.substr(start, (end - start + 1));
            }
            vector<string> palindromes = manacher.findAllPalindromes(input);
            if (palindromes.empty()) {
                cout << "No palindromes found!" << endl;
            } else {
                cout << "All palindromic substrings found:" << endl;
                for (size_t i = 0; i < palindromes.size(); i++) {
                    cout << (i + 1) << ". \"" << palindromes[i] << "\"" << endl;
                }
                cout << "Total palindromes: " << palindromes.size() << endl;
            }
        }
        else if (choice == "3") {
            cout << "Enter string: ";
            getline(cin, input);
            // Trim leading/trailing whitespace
            size_t start = input.find_first_not_of(" \t\r\n");
            if (start != string::npos) {
                size_t end = input.find_last_not_of(" \t\r\n");
                input = input.substr(start, (end - start + 1));
            }
            if (manacher.isPalindrome(input)) {
                cout << "\"" << input << "\" is a palindrome!" << endl;
            } else {
                cout << "\"" << input << "\" is not a palindrome!" << endl;
            }
        }
        else if (choice == "4") {
            cout << "Exiting..." << endl;
            return 0;
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}
