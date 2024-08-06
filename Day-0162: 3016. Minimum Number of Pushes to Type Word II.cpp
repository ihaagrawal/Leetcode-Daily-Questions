// 3016. Minimum Number of Pushes to Type Word II (MEDIUM)
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2024-08-06


class Solution {
public:
    int minimumPushes(string word) {
        int result = 0;
        vector<int> count(26);
        for (char& ch : word) ++count[ch - 'a'];
        sort(count.rbegin(), count.rend());
        for (int i = 0; i < 26; ++i) result += (i / 8 + 1) * count[i];
        return result;
    }
};
