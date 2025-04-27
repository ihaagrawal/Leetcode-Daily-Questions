// 3392. Count Subarrays of Length Three With a Condition (EASY)
// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/?envType=daily-question&envId=2025-04-27

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; 

        int count = 0;
        for (int i = 0; i <= n - 3; ++i) {
            if (nums[i] + nums[i + 2] == nums[i + 1] / 2.0) {
                count++;
            }
        }
        return count;
    }
};
