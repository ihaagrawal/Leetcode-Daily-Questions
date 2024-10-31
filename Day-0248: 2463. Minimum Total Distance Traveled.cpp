// 2463. Minimum Total Distance Traveled (HARD)
// https://leetcode.com/problems/minimum-total-distance-traveled/description/?envType=daily-question&envId=2024-10-31


class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();
        
        const long long INF = 1e18; // Custom large value to avoid overflow
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, INF));
        dp[0][0] = 0;

        for (int j = 1; j <= m; ++j) {
            dp[j][0] = 0;
            for (int i = 1; i <= n; ++i) {
                long long sum = 0;
                for (int k = 0; k <= min(i, factory[j - 1][1]); ++k) {
                    if (i - k >= 0) {
                        if (k > 0) {
                            sum += abs(robot[i - k] - factory[j - 1][0]);
                        }
                        if (dp[j - 1][i - k] != INF) {
                            dp[j][i] = min(dp[j][i], dp[j - 1][i - k] + sum);
                        }
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};
