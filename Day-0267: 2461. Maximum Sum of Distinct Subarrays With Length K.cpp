// 2461. Maximum Sum of Distinct Subarrays With Length K (MEDIUM)
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/?envType=daily-question&envId=2024-11-19


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> distinct;
        long long maxSum = 0, currentSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (distinct.count(nums[right])) {
                currentSum -= nums[left];
                distinct.erase(nums[left]);
                ++left;
            }

            distinct.insert(nums[right]);
            currentSum += nums[right];

            if (right - left + 1 == k) {
                maxSum = max(maxSum, currentSum);
                currentSum -= nums[left];
                distinct.erase(nums[left]);
                ++left;
            }
        }

        return maxSum;
    }
};
