// 3335. Total Characters in String After Transformations I (MEDIUM)
// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/?envType=daily-question&envId=2025-05-13

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> counts(26, 0);

        for (char c : s) counts[c - 'a']++;

        for (int i = 0; i < t; ++i) {
            long long zCount = counts[25]; 
            rotate(counts.rbegin(), counts.rbegin() + 1, counts.rend());
            counts[1] = (counts[1] + zCount) % MOD;
        }

        long long totalLength = 0;
        for (long long count : counts) totalLength = (totalLength + count) % MOD;

        return totalLength;
    }
};
