// 1590. Make Sum Divisible by P (MEDIUM)
// https://leetcode.com/problems/make-sum-divisible-by-p/description/?envType=daily-question&envId=2024-10-03


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum = (total_sum + num) % p;
        }

        if (total_sum == 0) return 0;

        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;
        int prefix_sum = 0, result = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            int target = (prefix_sum - total_sum + p) % p;
            if (prefix_map.count(target)) {
                result = min(result, i - prefix_map[target]);
            }
            prefix_map[prefix_sum] = i;
        }

        return result == nums.size() ? -1 : result;
    }
};
