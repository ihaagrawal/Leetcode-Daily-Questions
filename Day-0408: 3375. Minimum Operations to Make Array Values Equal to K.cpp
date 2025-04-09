// 3375. Minimum Operations to Make Array Values Equal to K (EASY)
// https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/?envType=daily-question&envId=2025-04-09

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int num : nums) {
            if (num < k) return -1;
        }

        unordered_set<int> unique_values;
        for (int num : nums) {
            if (num > k) unique_values.insert(num);
        }

        return unique_values.size();
    }
};
