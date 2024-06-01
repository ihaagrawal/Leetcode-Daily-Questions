// 977. Squares of a Sorted Array (EASY)
// https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            nums[i] = (nums[i] * nums[i]);
        sort(nums.begin(), nums.end());
        return nums;
    }
};
