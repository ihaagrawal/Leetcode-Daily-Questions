// 1813. Sentence Similarity III (MEDIUM)
// https://leetcode.com/problems/sentence-similarity-iii/description/?envType=daily-question&envId=2024-10-06

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        int n1 = words1.size(), n2 = words2.size();
        int i = 0, j = 0;
        
        while (i < n1 && i < n2 && words1[i] == words2[i]) i++;
        while (j < n1 - i && j < n2 - i && words1[n1 - j - 1] == words2[n2 - j - 1]) j++;
        return i + j == min(n1, n2);
    }
    
private:
    vector<string> split(const string& sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) words.push_back(word);
        return words;
    }
};
