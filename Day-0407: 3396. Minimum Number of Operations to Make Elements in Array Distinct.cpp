// 3396. Minimum Number of Operations to Make Elements in Array Distinct (EASY)
// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/?envType=daily-question&envId=2025-04-08


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();
        int lastDuplicateIndex = -1;

        for (int i = n - 1; i >= 0; --i) {
            if (seen.count(nums[i])) {
                lastDuplicateIndex = i;
                break;
            }
            seen.insert(nums[i]);
        }

        if (lastDuplicateIndex == -1) return 0; 

        return (lastDuplicateIndex + 3) / 3;
    }
};
