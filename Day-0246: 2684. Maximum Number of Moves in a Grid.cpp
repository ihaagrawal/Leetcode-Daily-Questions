// 2684. Maximum Number of Moves in a Grid (MEDIUM)
// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/?envType=daily-question&envId=2024-10-29

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int j = m - 2; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                
                if (i - 1 >= 0 && grid[i][j] < grid[i - 1][j + 1]) dp[i][j] = max(dp[i][j], dp[i-1][j+1] + 1);
                if (grid[i][j] < grid[i][j + 1]) dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
                if (i + 1 < n && grid[i][j] < grid[i + 1][j + 1]) dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
            }
        }

        int moves = 0;
        for (int i = 0; i < n; i++)
            moves = max(moves, dp[i][0]);

        return moves;
    }
};
