class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        
        // Count the frequency of each character
        for (char c : s) {
            count[c]++;
        }
        
        int length = 0;
        bool oddFound = false;
        
        // Iterate over the character frequencies
        for (auto& pair : count) {
            if (pair.second % 2 == 0) {
                length += pair.second;  // Use all characters if count is even
            } else {
                length += pair.second - 1;  // Use the maximum even part of the count
                oddFound = true;  // Mark that we have an odd count
            }
        }
        
        // If there was at least one odd count, we can use one odd character as the center
        if (oddFound) {
            length++;
        }
        
        return length;
    }
};
