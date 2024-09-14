// 2419. Longest Subarray With Maximum Bitwise AND (MEDIUM)
// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/?envType=daily-question&envId=2024-09-14


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end()); 
        
        int longest = 0;
        int current_length = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == max_val) {
                current_length++;  
                longest = max(longest, current_length); 
            } else current_length = 0;  
            
        }
        
        return longest;  
    }
};
