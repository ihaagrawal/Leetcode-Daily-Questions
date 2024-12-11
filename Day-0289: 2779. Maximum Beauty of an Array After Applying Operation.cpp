// 2779. Maximum Beauty of an Array After Applying Operation (MEDIUM)
// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/?envType=daily-question&envId=2024-12-11


class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int maxBeauty = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > 2 * k) ++left;
            maxBeauty = max(maxBeauty, right - left + 1);
        }

        return maxBeauty;
    }
};
