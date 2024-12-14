// 2762. Continuous Subarrays (MEDIUM)
// https://leetcode.com/problems/continuous-subarrays/description/?envType=daily-question&envId=2024-12-14

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        unordered_map<int, int> freq;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;

            while (true) {
                int max_val = INT_MIN;
                int min_val = INT_MAX;
                for (auto& p : freq) {
                    max_val = max(max_val, p.first);
                    min_val = min(min_val, p.first);
                }
                if (max_val - min_val > 2) {
                    freq[nums[left]]--;
                    if (freq[nums[left]] == 0) freq.erase(nums[left]);
                    left++;
                } else break;
            }

            result += right - left + 1;
        }

        return result;
    }
};
