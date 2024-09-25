// 2416. Sum of Prefix Scores of Strings (HARD)
// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/?envType=daily-question&envId=2024-09-25


struct TrieNode {
    int prefixScore;
    TrieNode *children[26];
    
    TrieNode () {
        prefixScore = 0;
        memset(children, 0, sizeof(children));
    }
    
    void insertWord(string &word, int index) {
        if (index) prefixScore++;
        if (index == word.size()) return;
        if (!children[word[index] - 'a']) children[word[index] - 'a'] = new TrieNode();
        children[word[index] - 'a']->insertWord(word, index + 1);
    }
    
    int calculatePrefixScore(string &word, int index) {
        if (index == word.size()) return prefixScore;
        return prefixScore + children[word[index] - 'a']->calculatePrefixScore(word, index + 1);
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode *trie = new TrieNode();
        for (string &word : words) {
            trie->insertWord(word, 0);
        }
        vector<int> result;
        for (string &word : words) {
            result.push_back(trie->calculatePrefixScore(word, 0));
        }
        return result;
    }
};
