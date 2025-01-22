// 1765. Map of Highest Peak (MEDIUM)
// https://leetcode.com/problems/map-of-highest-peak/description/?envType=daily-question&envId=2025-01-22

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> result(n, vector<int>(m, -1));
        vector<int> rows = {0, 1, 0, -1};
        vector<int> cols = {1, 0, -1, 0};
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newx = x + rows[i], newy = y + cols[i];
                if (newx >= 0 && newx < n && newy >= 0 && newy < m && result[newx][newy] == -1) {
                    result[newx][newy] = result[x][y] + 1;
                    q.push({newx, newy});
                }
            }
        }

        return result;
    }
};
