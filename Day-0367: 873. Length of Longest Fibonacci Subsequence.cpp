// 873. Length of Longest Fibonacci Subsequence (MEDIUM)
// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/?envType=daily-question&envId=2025-02-27


class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        unordered_map<int, int> dp;
        
        for (int i = 0; i < n; ++i) {
            index[arr[i]] = i;
        }
        
        int maxLength = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int prev = arr[i] - arr[j];
                if (prev < arr[j] && index.count(prev)) {
                    int k = index[prev];
                    int len = dp[k * n + j] + 1;
                    dp[j * n + i] = len;
                    maxLength = max(maxLength, len);
                } else {
                    dp[j * n + i] = 2;
                }
            }
        }
        
        return maxLength > 2 ? maxLength : 0;
    }
};
