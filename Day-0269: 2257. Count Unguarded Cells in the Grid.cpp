// 2257. Count Unguarded Cells in the Grid (MEDIUM)
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/?envType=daily-question&envId=2024-11-21


class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Mark guards and walls on the grid
        for (auto& g : guards) grid[g[0]][g[1]] = 1;
        for (auto& w : walls) grid[w[0]][w[1]] = 2;
        
        // Mark guarded cells
        for (auto& g : guards) {
            int x = g[0], y = g[1];
            
            for (int i = x + 1; i < m && grid[i][y] != 2 && grid[i][y] != 1; i++) 
                if (grid[i][y] == 0) grid[i][y] = -1;
            
            for (int i = x - 1; i >= 0 && grid[i][y] != 2 && grid[i][y] != 1; i--) 
                if (grid[i][y] == 0) grid[i][y] = -1;
            
            for (int j = y + 1; j < n && grid[x][j] != 2 && grid[x][j] != 1; j++) 
                if (grid[x][j] == 0) grid[x][j] = -1;
            
            for (int j = y - 1; j >= 0 && grid[x][j] != 2 && grid[x][j] != 1; j--) 
                if (grid[x][j] == 0) grid[x][j] = -1;
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) count++;
            }
        }
        
        return count;
    }
};
