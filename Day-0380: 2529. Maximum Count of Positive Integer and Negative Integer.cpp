// 2529. Maximum Count of Positive Integer and Negative Integer (EASY)
// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/?envType=daily-question&envId=2025-03-12

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, pos = 0, n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] < 0) neg++;
            else if(nums[i] > 0) pos++;
        }
        return pos > neg ? pos : neg;
    }
};
