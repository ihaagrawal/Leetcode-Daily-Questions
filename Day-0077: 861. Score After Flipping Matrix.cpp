// 861. Score After Flipping Matrix (MEDIUM)
// https://leetcode.com/problems/score-after-flipping-matrix/?envType=daily-question&envId=2024-05-13

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();
        
        for (int i = 0; i < numRows; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < numCols; ++j) {
                    grid[i][j] ^= 1; 
                }
            }
        }

        for (int j = 0; j < numCols; ++j) {
            int numZeros = 0;
            for (int i = 0; i < numRows; ++i) {
                numZeros += grid[i][j] == 0;
            }
            if (numZeros > numRows - numZeros) {
                for (int i = 0; i < numRows; ++i) {
                    grid[i][j] ^= 1;
                }
            }
        }

        int score = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                score += grid[i][j] << (numCols - j - 1);  
            }
        }

        return score;
    }
};
