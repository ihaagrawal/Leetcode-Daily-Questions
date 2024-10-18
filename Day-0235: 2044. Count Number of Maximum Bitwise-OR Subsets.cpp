// 2044. Count Number of Maximum Bitwise-OR Subsets (MEDIUM)
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/?envType=daily-question&envId=2024-10-18


class Solution {
public:

    int fn(int i, int current_or, vector<int>& nums, int n, int max_or){
        if(i < 0) return (current_or == max_or) ? 1 : 0;
        int not_take = fn(i-1, current_or, nums, n, max_or);
        int take = fn(i-1, current_or | nums[i], nums, n, max_or);
        return not_take + take;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int max_or = accumulate(nums.begin(), nums.end(), 0, bit_or<>());
        return fn(n-1, 0, nums, n, max_or);
    }
};
