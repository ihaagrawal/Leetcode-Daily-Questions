// 1829. Maximum XOR for Each Query (MEDIUM)
// https://leetcode.com/problems/maximum-xor-for-each-query/description/?envType=daily-question&envId=2024-11-08

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), xr = nums[0], max_xor = pow(2, maximumBit) - 1;
        for(int i=1;i<n;i++)  xr ^= nums[i];

        vector<int> result(n);
        for(int i=0;i<n;i++){
            result[i] = xr ^ max_xor;
            xr ^= nums[n-1-i];
        }

        return result;
    }
};
