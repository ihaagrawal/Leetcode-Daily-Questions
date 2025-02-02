// 1752. Check if Array Is Sorted and Rotated (EASY)
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02


class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1]) count++;
        }
        if(nums[n-1] > nums[0]) count++;
        return count > 1 ? false : true;
    }
};
