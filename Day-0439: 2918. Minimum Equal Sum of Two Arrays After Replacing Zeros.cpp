// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros (MEDIUM)
// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/?envType=daily-question&envId=2025-05-10

class Solution {
public:
    long long minSum(vector<int>& array1, vector<int>& array2) {
        long long total1 = 0, total2 = 0;
        int zeroCount1 = 0, zeroCount2 = 0;

        for (int value : array1) {
            if (value == 0) zeroCount1++;
            total1 += value;
        }

        for (int value : array2) {
            if (value == 0) zeroCount2++;
            total2 += value;
        }

        if (zeroCount1 == 0 && zeroCount2 == 0) return total1 == total2 ? total1 : -1;
        else if (zeroCount1 == 0) return (total2 + zeroCount2 <= total1) ? total1 : -1;
        else if (zeroCount2 == 0) return (total1 + zeroCount1 <= total2) ? total2 : -1;

        return max(total1 + zeroCount1, total2 + zeroCount2);
    }
};
