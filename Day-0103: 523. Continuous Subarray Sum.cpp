// 523. Continuous Subarray Sum (MEDIUM)
// https://leetcode.com/problems/continuous-subarray-sum/description/?envType=daily-question&envId=2024-06-08

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;  

        unordered_map<int, int> mp;
        mp[0] = -1; 
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0) rem += k;  

            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] > 1) return true;  
            } else {
                mp[rem] = i;  
            }
        }

        return false;  
    }
};
