// 2577. Minimum Time to Visit a Cell In a Grid (HARD)
// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/?envType=daily-question&envId=2024-11-29


class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        int numRows = grid.size();
        int numCols = grid[0].size();
        
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>, 
                      greater<pair<int, pair<int, int>>>> minHeap;
        
        minHeap.push({0, {0, 0}}); // {time, {row, col}}
        
        vector<vector<int>> visited(numRows, vector<int>(numCols, 0));
        visited[0][0] = 1;
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!minHeap.empty()) {
            auto current = minHeap.top();
            int currentTime = current.first;
            int currentRow = current.second.first;
            int currentCol = current.second.second;
            
            minHeap.pop();
            
            if (currentRow == numRows - 1 && currentCol == numCols - 1) 
                return currentTime;
            
            for (auto dir : directions) {
                int newRow = currentRow + dir.first;
                int newCol = currentCol + dir.second;
                
                if (newRow >= 0 && newCol >= 0 && 
                    newRow < numRows && newCol < numCols && 
                    !visited[newRow][newCol]) {
                    
                    int waitTime = ((grid[newRow][newCol] - currentTime) % 2 == 0) ? 1 : 0;
                    int arrivalTime = max(currentTime + 1, grid[newRow][newCol] + waitTime);
                    
                    minHeap.push({arrivalTime, {newRow, newCol}});
                    visited[newRow][newCol] = 1;
                }
            }
        }
        return -1;
    }
};
