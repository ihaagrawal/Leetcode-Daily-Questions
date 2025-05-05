// 790. Domino and Tromino Tiling (MEDIUM)
// https://leetcode.com/problems/domino-and-tromino-tiling/description/?envType=daily-question&envId=2025-05-05

class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n <= 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        vector<long long> dp(n + 1, 0);
        dp[0] = 1; dp[1] = 1; dp[2] = 2, dp[3] = 5;

        for (int i = 4; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2 + long(dp[i - 3])) % MOD;
        }

        return dp[n];
    }
};
