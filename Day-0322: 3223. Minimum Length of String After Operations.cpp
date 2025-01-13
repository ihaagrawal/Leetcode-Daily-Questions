// 3223. Minimum Length of String After Operations (MEDIUM)
// https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13


class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        int del = 0;
        for (auto& p : freq) {
            int f = p.second;
            del += (f % 2 == 1) ? f - 1 : f - 2;
        }

        return s.length() - del;
    }
};
