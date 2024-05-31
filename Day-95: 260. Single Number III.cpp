// 260. Single Number III (MEDIUM)
// https://leetcode.com/problems/single-number-iii/description/?envType=daily-question&envId=2024-05-31

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0, n = nums.size();

        for(int i=0;i<n;i++){
            xr ^= nums[i];
        }

        long long rightmost = (xr & xr-1) ^ xr;
        long long b1 = 0, b2 = 0;

        for(int i=0;i<n;i++){
            if(nums[i] & rightmost) b1 = b1 ^ nums[i];
            else b2 = b2 ^ nums[i];
        }

        return {static_cast<int>(b1), static_cast<int>(b2)};
    }
};
