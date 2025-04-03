// 2874. Maximum Value of an Ordered Triplet II (MEDIUM)
// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/?envType=daily-question&envId=2025-04-03

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; 

        long long max_value = 0;
        int max_i = nums[0];
        vector<int> max_suffix(n, 0);

        max_suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            max_suffix[i] = max(max_suffix[i + 1], nums[i]);
        }

        for (int j = 1; j < n - 1; ++j) {
            if (max_i > nums[j]) { 
                max_value = max(max_value, (long long)(max_i - nums[j]) * max_suffix[j + 1]);
            }
            max_i = max(max_i, nums[j]);
        }

        return max_value;
    }
};
