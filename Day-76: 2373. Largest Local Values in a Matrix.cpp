// 2373. Largest Local Values in a Matrix (EASY)
// https://leetcode.com/problems/largest-local-values-in-a-matrix/description/

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0));

        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int maxVal = grid[i - 1][j - 1];
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        maxVal = max(maxVal, grid[i + di][j + dj]);
                    }
                }
                maxLocal[i - 1][j - 1] = maxVal;
            }
        }

        return maxLocal;
    }
};
