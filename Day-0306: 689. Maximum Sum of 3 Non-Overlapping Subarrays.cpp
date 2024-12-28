// 689. Maximum Sum of 3 Non-Overlapping Subarrays (HARD)
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/?envType=daily-question&envId=2024-12-28


class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        vector<int> left(n, 0), right(n, 0);
        int maxSum = 0;
        for (int i = k - 1; i < n; ++i) {
            int currSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            if (currSum > maxSum) {
                maxSum = currSum;
                left[i] = i + 1 - k;
            } else {
                left[i] = left[i - 1];
            }
        }

        maxSum = 0;
        for (int i = n - k; i >= 0; --i) {
            int currSum = prefixSum[i + k] - prefixSum[i];
            if (currSum >= maxSum) {
                maxSum = currSum;
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }

        vector<int> result(3, -1);
        maxSum = 0;
        for (int i = k; i <= n - 2 * k; ++i) {
            int l = left[i - 1], r = right[i + k];
            int currSum = (prefixSum[l + k] - prefixSum[l]) +
                          (prefixSum[i + k] - prefixSum[i]) +
                          (prefixSum[r + k] - prefixSum[r]);
            if (currSum > maxSum) {
                maxSum = currSum;
                result = {l, i, r};
            }
        }

        return result;
    }
};
