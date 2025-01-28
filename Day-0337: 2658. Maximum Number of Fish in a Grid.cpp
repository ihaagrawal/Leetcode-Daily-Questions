// 2658. Maximum Number of Fish in a Grid (MEDIUM)
// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28


class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        // Helper function for DFS
        auto dfs = [&](int r, int c, auto& dfs) -> int {
            // Check bounds and whether it's a water cell
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return 0;
            
            // Collect fish and mark cell as visited
            int fish = grid[r][c];
            grid[r][c] = 0;

            // Explore all 4 adjacent cells
            fish += dfs(r + 1, c, dfs);
            fish += dfs(r - 1, c, dfs);
            fish += dfs(r, c + 1, dfs);
            fish += dfs(r, c - 1, dfs);

            return fish;
        };

        // Iterate through the grid
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0) { // Start DFS if it's a water cell
                    maxFish = max(maxFish, dfs(r, c, dfs));
                }
            }
        }

        return maxFish;
    }
};
