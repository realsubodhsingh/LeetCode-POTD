class Solution {
public:
    int appendCharacters(string s, string t) {
      int i = 0, j = 0;
        int s_len = s.length(), t_len = t.length();
        
        // Traverse the string s with pointer i and string t with pointer j
        while (i < s_len && j < t_len) {
            if (s[i] == t[j]) {
                j++; // Move to the next character in t
            }
            i++; // Move to the next character in s
        }
        
        // If we have not matched all characters in t, return the number of remaining characters in t
        return t_len - j;
    }
};
