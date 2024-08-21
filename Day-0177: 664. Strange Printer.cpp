// 664. Strange Printer (HARD)
// https://leetcode.com/problems/strange-printer/description/?envType=daily-question&envId=2024-08-21


class Solution {
public:

    int solve(int i, int j, const string& s, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        char ch = s[i];
        int result = 1 + solve(i + 1, j, s, dp);
        for (int k = i + 1; k <= j; k++) {
            if (s[k] == ch) {       
                int ans = solve(i, k - 1, s, dp) + solve(k + 1, j, s, dp);
                result = min(result, ans);
            }
        }
        return dp[i][j] = result;
    }

    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, s, dp);
    }

    
};
