// 3342. Find Minimum Time to Reach Last Room II (MEDIUM)
// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/description/?envType=daily-question&envId=2025-05-08

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size(), cols = moveTime[0].size();
        vector<vector<int>> minTime(rows, vector<int>(cols, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, 0, 0});

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!minHeap.empty()) {
            auto currentCell = minHeap.top();
            minHeap.pop();
            int currentTime = currentCell[0];
            int currentRow = currentCell[1];
            int currentCol = currentCell[2];

            if (currentTime >= minTime[currentRow][currentCol]) continue;
            minTime[currentRow][currentCol] = currentTime;

            if (currentRow == rows - 1 && currentCol == cols - 1) 
                return currentTime;

            for (auto [rowOffset, colOffset] : directions) {
                int nextRow = currentRow + rowOffset, nextCol = currentCol + colOffset;
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols) {
                    int movementCost = (currentRow + currentCol) % 2 + 1;
                    int allowedStartTime = max(moveTime[nextRow][nextCol], currentTime);
                    int nextCellTime = allowedStartTime + movementCost;

                    if (nextCellTime < minTime[nextRow][nextCol]) {
                        minHeap.push({nextCellTime, nextRow, nextCol});
                    }
                }
            }
        }

        return -1;
    }
};
