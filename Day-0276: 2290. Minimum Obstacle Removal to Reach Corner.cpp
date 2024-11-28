// 2290. Minimum Obstacle Removal to Reach Corner (HARD)
// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/?envType=daily-question&envId=2024-11-28


class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        cost[0][0] = 0;
        
        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {1, -1, 0, 0};
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            for (int d = 0; d < 4; ++d) {
                int nx = x + dirX[d], ny = y + dirY[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = cost[x][y] + grid[nx][ny];
                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;
                        if (grid[nx][ny] == 1) dq.push_back({nx, ny});
                        else dq.push_front({nx, ny});
                    }
                }
            }
        }
        
        return cost[m - 1][n - 1];
    }
};
