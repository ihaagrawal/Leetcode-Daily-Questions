// 2845. Count of Interesting Subarrays (MEDIUM)
// https://leetcode.com/problems/count-of-interesting-subarrays/description/?envType=daily-question&envId=2025-04-25

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> count_mod;
        count_mod[0] = 1;
        int prefix_mod = 0;
        long long result = 0;

        for (int num : nums) {
            if (num % modulo == k) {
                prefix_mod = (prefix_mod + 1) % modulo;
            }
            int target_mod = (prefix_mod - k + modulo) % modulo;
            if (count_mod.find(target_mod) != count_mod.end()) {
                result += count_mod[target_mod];
            }
            count_mod[prefix_mod]++;
        }

        return result;
    }
};
