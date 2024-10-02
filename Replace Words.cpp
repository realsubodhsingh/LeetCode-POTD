class Solution {
public:
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool is_end_of_word;

        TrieNode() {
            is_end_of_word = false;
        }
    };

    class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode();
        }

        void insert(const string& word) {
            TrieNode* node = root;
            for (char ch : word) {
                if (node->children.find(ch) == node->children.end()) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->is_end_of_word = true;
        }

        string search_shortest_prefix(const string& word) {
            TrieNode* node = root;
            string prefix = "";
            for (char ch : word) {
                if (node->children.find(ch) == node->children.end()) {
                    break;
                }
                node = node->children[ch];
                prefix += ch;
                if (node->is_end_of_word) {
                    return prefix;
                }
            }
            return word;
        }
    };

    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& root : dictionary) {
            trie.insert(root);
        }

        stringstream ss(sentence);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(trie.search_shortest_prefix(word));
        }

        string result = "";
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) {
                result += " ";
            }
            result += words[i];
        }

        return result;
    }
};




// Question Description

/* 
648. Replace Words
Medium

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
 

Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.*/
