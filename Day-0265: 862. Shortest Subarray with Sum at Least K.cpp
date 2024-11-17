// 862. Shortest Subarray with Sum at Least K (HARD)
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/?envType=daily-question&envId=2024-11-17

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<long long> prefixSum(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int min_len = INT_MAX;

        for (int j = 0; j <= n; ++j) {
            while (!dq.empty() && prefixSum[j] - prefixSum[dq.front()] >= k) {
                min_len = min(min_len, j - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefixSum[j] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(j);
        }

        return min_len == INT_MAX ? -1 : min_len;
    }
};
