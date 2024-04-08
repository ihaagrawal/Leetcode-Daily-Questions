// 713. Subarray Product Less Than K (MEDIUM)
// https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int n = nums.size(), product = 1, count {};
        int left = 0, right = 0;
        while(right < n)
        {
            product *= nums[right++];
            while(left < right && product >= k)
                product /= nums[left++];
            
            count += (right - left);
        }
        return count;
    }
};
