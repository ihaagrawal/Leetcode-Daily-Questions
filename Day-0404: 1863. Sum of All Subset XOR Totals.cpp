// 1863. Sum of All Subset XOR Totals (EASY)
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2025-04-05

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sumTotal = 0;

        for (int num : nums) {
            sumTotal |= num;
        }
        return sumTotal << (nums.size() - 1);
    }
};
