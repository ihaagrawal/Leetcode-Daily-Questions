// 2843. Count Symmetric Integers (EASY)
// https://leetcode.com/problems/count-symmetric-integers/description/?envType=daily-question&envId=2025-04-11

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int num = low; num <= high; ++num) {
            std::string numStr = std::to_string(num);
            int len = numStr.size();

            if (len % 2 != 0) continue;

            int mid = len / 2;
            int sum1 = 0, sum2 = 0;

            for (int i = 0; i < mid; ++i) {
                sum1 += numStr[i] - '0';
                sum2 += numStr[mid + i] - '0';
            }

            if (sum1 == sum2) {
                ++count;
            }
        }

        return count;
    }
};
