// 330. Patching Array (HARD)
// https://leetcode.com/problems/patching-array/description/?envType=daily-question&envId=2024-06-16

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long max_cover = 0; // max number we can cover so far
        int patches = 0;    // number of patches added

        int i = 0;
        while (max_cover < n) {
            if (i < nums.size() && nums[i] <= max_cover + 1) {
                max_cover += nums[i++];
            } else {
                // Add max_cover + 1 to nums
                max_cover += max_cover + 1;
                patches++;
            }
        }

        return patches;
    }
};
