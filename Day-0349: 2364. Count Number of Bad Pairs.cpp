// 2364. Count Number of Bad Pairs (MEDIUM)
// https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            if (freq.find(diff) != freq.end()) {
                goodPairs += freq[diff];
            }
            freq[diff]++;
        }

        long long totalPairs = 1LL * n * (n - 1) / 2;
        return totalPairs - goodPairs;
    }
};
