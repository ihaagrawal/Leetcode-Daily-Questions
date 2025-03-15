// 2560. House Robber IV (MEDIUM)
// https://leetcode.com/problems/house-robber-iv/description/?envType=daily-question&envId=2025-03-15

class Solution {
public:

    bool canSteal(vector<int>& nums, int k, int mid){
        int count = 0, i = 0, n = nums.size();
        
        while(i < n){
            if(nums[i] <= mid){
                count++;
                i += 2;
            }else i++;
        }

        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while(left < right){
            int mid = (left + right) / 2;
            if(canSteal(nums, k, mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};
