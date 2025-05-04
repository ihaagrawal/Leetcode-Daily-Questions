// 1128. Number of Equivalent Domino Pairs (EASY)
// https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?envType=daily-question&envId=2025-05-04

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> freqMap;
        int count = 0;

        for (const auto& domino : dominoes) {
            int a = domino[0];
            int b = domino[1];
            int key = a < b ? a * 10 + b : b * 10 + a;
            count += freqMap[key];
            freqMap[key]++;
        }

        return count;
    }
};
