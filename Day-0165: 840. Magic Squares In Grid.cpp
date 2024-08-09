// 840. Magic Squares In Grid (MEDIUM)
// https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2024-08-09

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (n < 3 || m < 3) return 0;
        
        int count = 0;
        
        // Helper function to check if a 3x3 grid is a magic square
        auto isMagicSquare = [](const vector<vector<int>>& subgrid) {
            vector<int> nums(9);
            int k = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    nums[k++] = subgrid[i][j];
                }
            }
            
            sort(nums.begin(), nums.end());
            // Check if all numbers from 1 to 9 are present
            for (int i = 0; i < 9; ++i) {
                if (nums[i] != i + 1) return false;
            }

            int sum = 15; // Sum of rows, columns, diagonals for a 3x3 magic square
            // Check rows
            for (int i = 0; i < 3; ++i) {
                if (subgrid[i][0] + subgrid[i][1] + subgrid[i][2] != sum) return false;
            }
            // Check columns
            for (int i = 0; i < 3; ++i) {
                if (subgrid[0][i] + subgrid[1][i] + subgrid[2][i] != sum) return false;
            }
            // Check diagonals
            if (subgrid[0][0] + subgrid[1][1] + subgrid[2][2] != sum) return false;
            if (subgrid[0][2] + subgrid[1][1] + subgrid[2][0] != sum) return false;
            
            return true;
        };
        
        for (int i = 0; i <= n - 3; ++i) {
            for (int j = 0; j <= m - 3; ++j) {
                vector<vector<int>> subgrid(3, vector<int>(3));
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        subgrid[k][l] = grid[i + k][j + l];
                    }
                }
                if (isMagicSquare(subgrid)) {
                    ++count;
                }
            }
        }
        
        return count;
    }
};
