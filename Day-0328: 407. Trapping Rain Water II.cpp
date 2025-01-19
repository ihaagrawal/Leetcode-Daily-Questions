// 407. Trapping Rain Water II (HARD)
// https://leetcode.com/problems/trapping-rain-water-ii/description/?envType=daily-question&envId=2025-01-19


#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        if (n < 3 || m < 3) return 0; // No trapping possible in small grids

        // Min-heap to store the boundary cells
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int volume = 0;

        // Add all boundary cells to the priority queue
        for (int i = 0; i < n; ++i) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][m - 1], {i, m - 1}});
            visited[i][0] = visited[i][m - 1] = true;
        }
        for (int j = 1; j < m - 1; ++j) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[n - 1][j], {n - 1, j}});
            visited[0][j] = visited[n - 1][j] = true;
        }

        // Process the cells in the min-heap
        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            // Check neighbors
            for (auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    // Water trapped is the difference between current height and neighbor height
                    volume += max(0, height - heightMap[nx][ny]);
                    // Add the neighbor cell to the queue with the updated height
                    pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }

        return volume;
    }
};
