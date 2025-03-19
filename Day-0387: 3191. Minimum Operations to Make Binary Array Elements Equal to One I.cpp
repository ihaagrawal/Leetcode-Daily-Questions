// 3191. Minimum Operations to Make Binary Array Elements Equal to One I (MEDIUM)
// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/?envType=daily-question&envId=2025-03-19

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count_flips = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (i + 2 < n) {
                    ++count_flips;
                    nums[i] ^= 1;
                    nums[i+1] ^= 1;
                    nums[i+2] ^= 1;
                } else return -1;
            }
        }

        for (int num : nums) {
            if (num == 0) {
                return -1;
            }
        }

        return count_flips;
    }
};
