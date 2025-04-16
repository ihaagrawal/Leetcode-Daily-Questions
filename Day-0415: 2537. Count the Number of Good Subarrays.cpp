// 2537. Count the Number of Good Subarrays (MEDIUM)
// https://leetcode.com/problems/count-the-number-of-good-subarrays/description/?envType=daily-question&envId=2025-04-16

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> count_map;
        long long current_pairs = 0, result = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            current_pairs += count_map[nums[right]];
            count_map[nums[right]]++;

            while (current_pairs >= k) {
                result += nums.size() - right; 
                count_map[nums[left]]--;
                current_pairs -= count_map[nums[left]];
                left++;
            }
        }

        return result;
    }
};
