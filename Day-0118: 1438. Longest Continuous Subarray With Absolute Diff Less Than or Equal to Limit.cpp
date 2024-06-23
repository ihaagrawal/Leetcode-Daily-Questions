// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit (MEDIUM)
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/?envType=daily-question&envId=2024-06-23


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> st;
        int left = 0, result = 1;

        for(int right=0;right<n;right++){
            st.insert(nums[right]);
            while(!st.empty() && *st.rbegin()-*st.begin() > limit){
                st.erase(st.find(nums[left++]));
            }
            result = max(result, right-left+1);
        }
        return result;
    }
};
