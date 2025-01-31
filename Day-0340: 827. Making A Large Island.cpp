// 827. Making A Large Island (HARD)
// https://leetcode.com/problems/making-a-large-island/description/?envType=daily-question&envId=2025-01-31


class Solution {
public:
    vector<int> rows = {1, 0, -1, 0};
    vector<int> cols = {0, 1, 0, -1};

    void dfs(int row, int col, int n, int m, int& count, int& lab, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<vector<int>>& label) {
        if (row >= n || row < 0 || col >= m || col < 0 || grid[row][col] != 1 || vis[row][col]) 
            return;

        // Mark the current cell as visited and increase the count and assign label
        vis[row][col] = true;
        label[row][col] = lab;
        count++;

        // Run dfs on each cell in 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + rows[i], ncol = col + cols[i];
            dfs(nrow, ncol, n, m, count, lab, grid, vis, label);
        }
    }

    void check(int row, int col, int n, int m, unordered_map<int, int>& area, vector<vector<int>>& label, int& max_area) {
        // Use a set to avoid duplicate island labels
        unordered_set<int> seen;
        int ar = 1; // Base area for flipping this `0` to `1`

        for (int i = 0; i < 4; i++) {
            int nrow = row + rows[i], ncol = col + cols[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                int island = label[nrow][ncol];
                if (island > 0 && seen.find(island) == seen.end()) {
                    ar += area[island];
                    seen.insert(island);
                }
            }
        }

        max_area = max(max_area, ar);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Create a visited grid to keep track of visited cells
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Create a grid to label the islands and a map to track their area
        vector<vector<int>> label(n, vector<int>(m, 0));
        unordered_map<int, int> area;
        int lab = 1;
        area[0] = 0;

        // Run dfs on cells which have value as 1 and are not visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int count = 0;
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, n, m, count, lab, grid, vis, label);
                    area[lab] = count;
                    lab++;
                }
            }
        }

        // Initial max area (case where the grid is already one large island)
        int max_area = 0;
        for (auto& [_, val] : area) {
            max_area = max(max_area, val);
        }

        // Check for each `0` cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    check(i, j, n, m, area, label, max_area);
                }
            }
        }

        return max_area;
    }
};
