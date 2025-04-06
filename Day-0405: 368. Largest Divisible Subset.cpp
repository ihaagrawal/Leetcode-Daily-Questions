// 368. Largest Divisible Subset (MEDIUM)
// https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2025-04-06

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        
        int maxIdx = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > dp[maxIdx]) {
                maxIdx = i;
            }
        }
        
        vector<int> result;
        for (int i = maxIdx; i >= 0; i = prev[i]) {
            result.push_back(nums[i]);
            if (prev[i] == -1) break;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
