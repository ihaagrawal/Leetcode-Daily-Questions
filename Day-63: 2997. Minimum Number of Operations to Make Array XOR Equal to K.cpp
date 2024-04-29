// 2997. Minimum Number of Operations to Make Array XOR Equal to K (MEDIUM)
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/?envType=daily-question&envId=2024-04-29

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xr=0;
        for(int i=0;i<nums.size();i++) xr ^= nums[i];
        xr ^= k;
        int count=0;
        while(xr>0){
            count += (xr%2);
            xr /= 2;
        }
        return count;
    }
};
