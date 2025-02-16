// 1718. Construct the Lexicographically Largest Valid Sequence (MEDIUM)
// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/?envType=daily-question&envId=2025-02-16


class Solution {
public:
    vector<int> result;
    vector<bool> used;

    bool backtrack(int index, int n) {
        if (index == result.size()) return true;
        if (result[index] != 0) return backtrack(index + 1, n);

        for (int num = n; num >= 1; --num) {
            if (used[num]) continue;
            if (num == 1 || (index + num < result.size() && result[index + num] == 0)) {
                result[index] = num;
                if (num > 1) result[index + num] = num;
                used[num] = true;

                if (backtrack(index + 1, n)) return true;

                result[index] = 0;
                if (num > 1) result[index + num] = 0;
                used[num] = false;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        result.resize(2 * n - 1, 0);
        used.resize(n + 1, false);
        backtrack(0, n);
        return result;
    }
};
