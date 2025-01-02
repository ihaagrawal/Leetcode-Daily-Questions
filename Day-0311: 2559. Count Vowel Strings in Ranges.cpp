// 2559. Count Vowel Strings in Ranges (MEDIUM)
// https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02


class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> prefixSum(words.size() + 1, 0);

        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        for (int i = 0; i < words.size(); ++i) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }

        for (const auto& query : queries) {
            int li = query[0], ri = query[1];
            ans.push_back(prefixSum[ri + 1] - prefixSum[li]);
        }

        return ans;
    }
};
