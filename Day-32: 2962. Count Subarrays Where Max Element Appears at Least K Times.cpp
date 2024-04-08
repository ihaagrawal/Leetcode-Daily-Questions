// 2962. Count Subarrays Where Max Element Appears at Least K Times (MEDIUM)
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ele_count = 0, count = 0;
        long long left = 0, right = 0, n = nums.size();
        long long max_ele = *max_element(nums.begin(), nums.end());

        while (right<n) {
            if(nums[right]==max_ele)
                ele_count++;
            while(ele_count>=k){
                if(nums[left]==max_ele)
                    ele_count--;
                left++;
                count += n-right;
            }
            right++;
        }
        
        return count;
    }
};
