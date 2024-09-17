// 884. Uncommon Words from Two Sentences (EASY)
// https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream iss(s1);
        vector<string> word1;
        string word;
        while (iss >> word) {
            word1.push_back(word);
        }

        istringstream iss2(s2);
        vector<string> word2;
        while (iss2 >> word) {
            word2.push_back(word);
        }

        unordered_set<string> uncommon;
        unordered_set<string> common;

        for(const string& w1: word1){
            if (common.count(w1) == 0) {
                if (uncommon.count(w1) == 0) {
                    uncommon.insert(w1);
                } else {
                    uncommon.erase(w1);
                    common.insert(w1);
                }
            }
        }

        for(const string& w2: word2){
            if (common.count(w2) == 0) {
                if (uncommon.count(w2) == 0) {
                    uncommon.insert(w2);
                } else {
                    uncommon.erase(w2);
                    common.insert(w2);
                }
            }
        }

        vector<string> result(uncommon.begin(), uncommon.end());
        return result;
    }
};
