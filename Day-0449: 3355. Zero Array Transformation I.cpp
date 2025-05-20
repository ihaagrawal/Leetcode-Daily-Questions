// 3355. Zero Array Transformation I (MEDIUM)
// https://leetcode.com/problems/zero-array-transformation-i/description/?envType=daily-question&envId=2025-05-20

class Solution {
public:
    bool isZeroArray(vector<int>& arr, vector<vector<int>>& operations) {
        vector<int> adjustment(arr.size() + 1, 0);

        for (const auto& op : operations) {
            adjustment[op[0]]++; 
            if (op[1] + 1 < arr.size()) adjustment[op[1] + 1]--; 
        }

        int runningSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            runningSum += adjustment[i]; 
            if (arr[i] > runningSum) return false; 
        }

        return true; 
    }
};
