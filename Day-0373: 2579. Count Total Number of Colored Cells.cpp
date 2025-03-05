// 2579. Count Total Number of Colored Cells (MEDIUM)
// https://leetcode.com/problems/count-total-number-of-colored-cells/description/?envType=daily-question&envId=2025-03-05

class Solution {
public:
    long long coloredCells(int n) {
        long long result = (2LL * n * n) - (2LL * n) + 1; 
        return result; 
    }
};
