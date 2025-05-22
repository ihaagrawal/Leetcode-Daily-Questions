// 3362. Zero Array Transformation III (MEDIUM)
// https://leetcode.com/problems/zero-array-transformation-iii/description/?envType=daily-question&envId=2025-05-22

class Solution {
public:
    int maxRemoval(vector<int>& arr, vector<vector<int>>& ops) {
        int n = arr.size();
        int m = ops.size();
        
        sort(ops.begin(), ops.end());
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int usedOps = 0;

        for (int currTime = 0, idx = 0; currTime < n; currTime++) {
            while (!minHeap.empty() && minHeap.top() < currTime) {
                minHeap.pop();
            }

            while (idx < m && ops[idx][0] <= currTime) {
                maxHeap.push(ops[idx][1]);
                idx++;
            }

            while (minHeap.size() < arr[currTime] && !maxHeap.empty() && maxHeap.top() >= currTime) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                usedOps++;
            }

            if (minHeap.size() < arr[currTime]) {
                return -1;
            }
        }

        return m - usedOps;
    }
};
