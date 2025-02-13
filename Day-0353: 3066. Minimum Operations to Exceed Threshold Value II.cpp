// 3066. Minimum Operations to Exceed Threshold Value II (MEDIUM)
// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/?envType=daily-question&envId=2025-02-13

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
        int count = 0;

        while (true) {
            long long smallest = minHeap.top(); minHeap.pop();
            long long secondSmallest = minHeap.top(); minHeap.pop();

            if (smallest >= k && secondSmallest >= k) return count;

            long long newSum = 2 * smallest + secondSmallest;
            minHeap.push(newSum);
            count++;
        }

        return count;
    }
};
