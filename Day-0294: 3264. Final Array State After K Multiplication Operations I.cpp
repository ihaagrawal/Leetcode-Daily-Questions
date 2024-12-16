// 3264. Final Array State After K Multiplication Operations I (EASY)
// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/?envType=daily-question&envId=2024-12-16


class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
            int minIndex = 0;
            for (int j = 1; j < nums.size(); ++j) {
                if (nums[j] < nums[minIndex]) minIndex = j;
            }
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};
