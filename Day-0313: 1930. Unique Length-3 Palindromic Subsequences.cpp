// 1930. Unique Length-3 Palindromic Subsequences (MEDIUM)
// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> charPositions(26);
        for (int i = 0; i < s.size(); ++i) {
            charPositions[s[i] - 'a'].push_back(i);
        }

        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (charPositions[i].size() < 2) continue;

            int left = charPositions[i][0];
            int right = charPositions[i].back();

            unordered_set<char> uniqueChars;
            for (int j = left + 1; j < right; ++j) {
                uniqueChars.insert(s[j]);
            }

            count += uniqueChars.size();
        }

        return count;
    }
};
