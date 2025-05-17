#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

// Problem: Given a string, find the length of the longest substring without repeating characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;  // Keeps track of characters in the current window
        int left = 0;              // Left side of the window
        int maxLen = 0;            // To store the length of the longest unique substring

        // Start expanding the window using the right pointer
        for (int right = 0; right < s.length(); ++right) {
            // If we see a duplicate, shrink the window from the left
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                left++;  // Move left forward until the duplicate is removed
            }

            seen.insert(s[right]);  // Add the current character to the set
            maxLen = max(maxLen, right - left + 1);  // Update max length if needed
        }

        return maxLen;  // Final answer
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);  // Read the input string

    Solution sol;
    int result = sol.lengthOfLongestSubstring(input);

    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
