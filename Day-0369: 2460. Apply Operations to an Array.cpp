// 2460. Apply Operations to an Array (EASY)
// https://leetcode.com/problems/apply-operations-to-an-array/description/?envType=daily-question&envId=2025-03-01


class Solution {
public:

    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        
        while (i < n && nums[i] != 0) i++;
        if (i == n) return;

        j = i + 1;
        while (j < n) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                while (i < n && nums[i] != 0) i++;
            }
            j++;
        }
    }

    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] = 2 * nums[i];
                nums[i+1] = 0;
            }
        }
        
        moveZeroes(nums);
        return nums;
    }
};
