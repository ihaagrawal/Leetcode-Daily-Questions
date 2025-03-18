// 2401. Longest Nice Subarray (MEDIUM)
// https://leetcode.com/problems/longest-nice-subarray/description/?envType=daily-question&envId=2025-03-18

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), max_len = 0;
        int i = 0, j = 0, res = 0;

        while(j < n){
            while(res & nums[j]){
                res ^= nums[i];
                i++;
            }
            res |= nums[j];
            max_len = max(max_len, j-i+1);
            j++;
        }
        return max_len;
    }
};
