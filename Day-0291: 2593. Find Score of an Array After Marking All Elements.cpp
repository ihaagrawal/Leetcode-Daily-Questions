// 2593. Find Score of an Array After Marking All Elements (MEDIUM)
// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13


class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        vector<bool> marked(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            pq.emplace(nums[i], i);
        }

        while (!pq.empty()) {
            auto [value, index] = pq.top();
            pq.pop();

            if (marked[index]) continue;

            score += value;
            marked[index] = true;
            if (index > 0) marked[index - 1] = true;
            if (index < n - 1) marked[index + 1] = true;
        }

        return score;
    }
};
