// 1568. Minimum Number of Days to Disconnect Island (HARD)
// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/?envType=daily-question&envId=2024-08-11

class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || vis[i][j]) return;

        vis[i][j] = true;

        dfs(grid, vis, i + 1, j);
        dfs(grid, vis, i - 1, j);
        dfs(grid, vis, i, j + 1);
        dfs(grid, vis, i, j - 1);
    }

    int count(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), days = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    days++;
                    dfs(grid, vis, i, j);
                }
            }
        }

        return days;
    }

    int minDays(vector<vector<int>>& grid) {
        if (count(grid) != 1) return 0;

        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; 
                    if (count(grid) != 1) return 1;
                    grid[i][j] = 1; 
                }
            }
        }

        return 2; 
    }
};
