class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
         vector<int> commonFreq(26, INT_MAX);
    
    for (const string& word : words) {
        // Frequency counter for the current word
        vector<int> wordFreq(26, 0);
        for (char ch : word) {
            wordFreq[ch - 'a']++;
        }
        
        // Update the common frequency counter
        for (int i = 0; i < 26; ++i) {
            commonFreq[i] = min(commonFreq[i], wordFreq[i]);
        }
    }
    
    // Extract the result from the common frequency counter
    vector<string> result;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < commonFreq[i]; ++j) {
            result.push_back(string(1, 'a' + i));
        }
    }
    
    return result;
    }
};
