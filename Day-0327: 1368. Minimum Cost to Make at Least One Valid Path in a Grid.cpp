// 1368. Minimum Cost to Make at Least One Valid Path in a Grid (HARD)
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18


#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        auto isValid = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0}); // cost, x, y
        cost[0][0] = 0;
        
        while (!pq.empty()) {
            auto [currentCost, x, y] = pq.top();
            pq.pop();
            
            if (x == m - 1 && y == n - 1) {
                return currentCost;
            }
            
            if (currentCost > cost[x][y]) continue;
            
            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d].first;
                int ny = y + directions[d].second;
                int newCost = currentCost + (d + 1 == grid[x][y] ? 0 : 1);
                
                if (isValid(nx, ny) && newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
        
        return -1; // unreachable
    }
};
