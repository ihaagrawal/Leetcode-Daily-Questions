// 1800. Maximum Ascending Subarray Sum (EASY)
// https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int currentSum = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) currentSum += nums[i];
            else {
                maxSum = max(maxSum, currentSum);
                currentSum = nums[i];
            }
        }

        maxSum = max(maxSum, currentSum);

        return maxSum;
    }
};
