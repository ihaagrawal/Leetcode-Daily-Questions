// 2901. Longest Unequal Adjacent Groups Subsequence II (MEDIUM)
// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/?envType=daily-question&envId=2025-05-16

class Solution {
public:
    bool dBy1(string w1, string w2) {
        if (w1.length() != w2.length()) return false;
        int dCnt = 0;
        for (int i = 0; i < w1.length(); i++) dCnt += w1[i] != w2[i];
        return dCnt == 1;
    }
    
    vector<string> getWordsInLongestSubsequence(vector<string>& w, vector<int>& g) {
        int n = g.size();
        vector<int> dp(n, 1), p(n, -1);
        int mx = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (g[i] != g[j] && dBy1(w[i], w[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    p[i] = j;
                }
            }
            mx = max(mx, dp[i]);
        }
        
        vector<string> res;
        for (int i = 0; i < n; i++) {
            if (mx == dp[i]) {
                while (i != -1) {
                    res.push_back(w[i]);
                    i = p[i];
                }
                break;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
