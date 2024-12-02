// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence (EASY)
// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/?envType=daily-question&envId=2024-12-02


class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 1;
        int n = sentence.size();
        int searchLen = searchWord.size();
        
        for (int i = 0; i < n; ) {
            if (sentence.substr(i, searchLen) == searchWord) return wordIndex;
            while (i < n && sentence[i] != ' ') i++;
        
            i++;
            wordIndex++;
        }
        
        return -1;
    }
};
