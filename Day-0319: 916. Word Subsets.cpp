// 916. Word Subsets (MEDIUM)
// https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10


class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        vector<string> result;

        unordered_map<char, int> mp;
        for (const string& str : words2) {
            unordered_map<char, int> temp;
            for (char c : str) temp[c]++;
            for (auto& [ch, freq] : temp) mp[ch] = max(mp[ch], freq);
        }

        for (const string& str : words1) {
            unordered_map<char, int> temp;
            for (char c : str) temp[c]++;
    
            bool isValid = true;
            for (auto& [ch, freq] : mp) {
                if (temp[ch] < freq) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) result.push_back(str);
        }

        return result;
    }
};
