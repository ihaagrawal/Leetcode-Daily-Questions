// 2873. Maximum Value of an Ordered Triplet I (EASY)
// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/?envType=daily-question&envId=2025-04-02

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        int max_prefix = nums[0];

        vector<int> max_suffix(n, 0);
        max_suffix[n - 1] = nums[n - 1];
        for (int k = n - 2; k >= 0; --k) {
            max_suffix[k] = max(max_suffix[k + 1], nums[k]);
        }

        for (int j = 1; j < n - 1; ++j) {
            long long value = (long long)(max_prefix - nums[j]) * max_suffix[j + 1];
            result = max(result, value);
            max_prefix = max(max_prefix, nums[j]);
        }

        return result;
    }
};
