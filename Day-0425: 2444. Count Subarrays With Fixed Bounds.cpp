// 2444. Count Subarrays With Fixed Bounds (HARD)
// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2025-04-26

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        int n=nums.size();
        int max_ind=-1, min_ind=-1, bad_ind=-1;
        long long count=0;

        for(int i=0;i<n;i++){
            if(nums[i]<mink || nums[i]>maxk) bad_ind=i;
            if(nums[i]==mink) min_ind=i;
            if(nums[i]==maxk) max_ind=i;

            long long smaller = min(min_ind, max_ind);
            long long temp = smaller - bad_ind;
            count += (temp<=0) ? 0 : temp;     
        }
        return count;
    }
};
