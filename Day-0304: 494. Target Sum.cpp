// 494. Target Sum (MEDIUM)
// https://leetcode.com/problems/target-sum/description/?envType=daily-question&envId=2024-12-26


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        
        vector<int> dp(2 * sum + 1, 0);
        dp[sum] = 1;
        
        for (int num : nums) {
            vector<int> next(2 * sum + 1, 0);
            for (int s = -sum; s <= sum; ++s) {
                if (dp[s + sum] > 0) {
                    next[s + sum + num] += dp[s + sum];
                    next[s + sum - num] += dp[s + sum];
                }
            }
            dp = move(next);
        }
        
        return dp[target + sum];
    }
};
