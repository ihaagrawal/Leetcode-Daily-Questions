// 2958. Length of Longest Subarray With at Most K Frequency (MEDIUM)
// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(), i;
        unordered_map<int, int> mp;
        int left=0, right=0, count=0;

        while(right<n){
            mp[nums[right]]++;
            while(left<right && mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;
            }
            count=max(count, right-left+1);
            right++;
        }
        return count;
    }
};
