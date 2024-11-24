// 1975. Maximum Matrix Sum (MEDIUM)
// https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2024-11-24


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total = 0;
        int neg = 0, mini = INT_MAX;
        
        for (const auto& row : matrix) {
            for (int val : row) {
                total += abs(val);
                if (val < 0) neg++;
                mini = min(mini, abs(val));
            }
        }
        
        if (neg % 2 != 0) total -= 2 * mini;
        return total;
    }
};
