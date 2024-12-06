// 2554. Maximum Number of Integers to Choose From a Range I (MEDIUM)
// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/?envType=daily-question&envId=2024-12-06


class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        int sum = 0, count = 0;

        for (int i = 1; i <= n; ++i) {
            if (bannedSet.find(i) != bannedSet.end()) continue;
            if (sum + i > maxSum)break;
            sum += i;
            ++count;
        }

        return count;
    }
};
