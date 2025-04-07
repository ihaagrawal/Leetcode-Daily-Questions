// 416. Partition Equal Subset Sum (MEDIUM)
// https://leetcode.com/problems/partition-equal-subset-sum/description/?envType=daily-question&envId=2025-04-07


class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int half = sum/2;
        if(sum % 2 != 0) return false;

        vector<vector<bool>> dp(n+1, vector<bool>(half+1));

        for(int i=0;i<n;i++) dp[i][0] = true;
        for(int j=1;j<half+1;j++) dp[0][j] = false;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=half;j++){
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            }
        }

        return dp[n][half];
    }
};
