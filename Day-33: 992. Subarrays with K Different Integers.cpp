// 992. Subarrays with K Different Integers (HARD)
// https://leetcode.com/problems/subarrays-with-k-different-integers/description/?envType=daily-question&envId=2024-03-30

class Solution {
public:

    int number(vector<int>nums, int k){
        int l=0, r=0, count=0, n=nums.size();
        map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                    mp.erase(nums[l]);
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return number(nums, k)-number(nums, k-1);
    }
};
