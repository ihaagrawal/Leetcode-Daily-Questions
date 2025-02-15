// 2698. Find the Punishment Number of an Integer (MEDIUM)
// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/?envType=daily-question&envId=2025-02-15


class Solution {
public:
    bool canPartition(const string& squareStr, int target, int start) {
        if (start == squareStr.size()) return target == 0;

        int num = 0;
        for (int i = start; i < squareStr.size(); ++i) {
            num = num * 10 + (squareStr[i] - '0');
            if (num > target) break;
            if (canPartition(squareStr, target - num, i + 1)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int punishmentSum = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            string squareStr = to_string(square);
            if (canPartition(squareStr, i, 0)) punishmentSum += square;
        }
        return punishmentSum;
    }
};
