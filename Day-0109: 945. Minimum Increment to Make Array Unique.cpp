// 945. Minimum Increment to Make Array Unique (MEDIUM)
// https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/?envType=daily-question&envId=2024-06-14

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        sort(nums.begin(), nums.end());

        for(int i=1;i<n;i++){
            if(nums[i] <= nums[i-1]){
                int newVal = nums[i-1] + 1;
                count += newVal - nums[i];
                nums[i] = newVal;
            }
        }

        return count;
    }
};
