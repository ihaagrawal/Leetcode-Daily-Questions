// 2017. Grid Game (MEDIUM)
// https://leetcode.com/problems/grid-game/description/?envType=daily-question&envId=2025-01-21


class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        
        vector<long long> prefixTop(n + 1, 0), prefixBottom(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixTop[i + 1] = prefixTop[i] + grid[0][i];
            prefixBottom[i + 1] = prefixBottom[i] + grid[1][i];
        }
        
        long long result = LLONG_MAX;
        
        for (int i = 0; i < n; ++i) {
            long long pointsAbove = prefixTop[n] - prefixTop[i + 1];
            long long pointsBelow = prefixBottom[i];
            long long secondRobotPoints = max(pointsAbove, pointsBelow);
            
            result = min(result, secondRobotPoints);
        }
        
        return result;
    }
};
