// 2503. Maximum Number of Points From Grid Queries (HARD)
// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/?envType=daily-question&envId=2025-03-28


class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();
        vector<int> result(k, 0);
        
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < k; ++i) {
            sortedQueries.emplace_back(queries[i], i);
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0);
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int points = 0;
        
        for (auto& [query, index] : sortedQueries) {
            while (!pq.empty() && pq.top().first < query) {
                auto [value, pos] = pq.top();
                pq.pop();
                
                int x = pos / n, y = pos % n;
                ++points;
                
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirs[d], ny = y + dirs[d + 1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        pq.emplace(grid[nx][ny], nx * n + ny);
                    }
                }
            }
            result[index] = points;
        }
        
        return result;
    }
};
