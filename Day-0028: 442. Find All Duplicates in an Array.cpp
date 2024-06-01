// 442. Find All Duplicates in an Array (MEDIUM)
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
                result.push_back(abs(nums[i]));
            else
                nums[idx] = -nums[idx];
        }
        return result;
    }
};
