// 2563. Count the Number of Fair Pairs (MEDIUM)
// https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2025-04-19

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i=0;i<n;i++){
            auto h = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            auto l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            count += (h - l);
        }

        return count;
    }
};
