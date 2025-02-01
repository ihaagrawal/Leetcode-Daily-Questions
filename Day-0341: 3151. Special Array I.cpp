// 3151. Special Array I (EASY)
// https://leetcode.com/problems/special-array-i/description/?envType=daily-question&envId=2025-02-01


class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        
        for(int i=1;i<n;i++){
            if(nums[i]%2==0 && nums[i-1]%2==0) return false;
            else if(nums[i]%2!=0 && nums[i-1]%2!=0) return false;
        }
        return true;
    }
};
