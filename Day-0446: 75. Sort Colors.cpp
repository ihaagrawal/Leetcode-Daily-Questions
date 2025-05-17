// 75. Sort Colors (MEDIUM)
// https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2025-05-17

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1, i = 0;
        while(i <= right){
            if(nums[i] == 0){
                swap(nums[left], nums[i]);
                left++;
                i++;
            }else if(nums[i] == 2){
                swap(nums[right], nums[i]);
                right--;
            }else i++;
        }
    }
};
