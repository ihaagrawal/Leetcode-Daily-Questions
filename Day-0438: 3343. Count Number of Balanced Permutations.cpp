// 3343. Count Number of Balanced Permutations (HARD)
// https://leetcode.com/problems/count-number-of-balanced-permutations/description/?envType=daily-question&envId=2025-05-09

class Solution {
    const static int MOD = 1e9 + 7;
    int numDigits, digitCount[10], sumRemaining[10], countRemaining[10], combination[81][81];
    long memo[10][361][41], productMemo[11];

    long calculateDFS(int digit, int sum, int remainingCount) {
        if (sum == 0 && remainingCount == 0) return productMemo[digit];
        if (digit == 10) return 0;
        if (sum > sumRemaining[digit] || remainingCount > countRemaining[digit]) return 0;
        if (memo[digit][sum][remainingCount] != -1) return memo[digit][sum][remainingCount];

        long result = 0;
        int currentSum = sum;
        for (int usedCount = 0, unusedCount = digitCount[digit]; 
             usedCount <= digitCount[digit] && currentSum >= 0 && remainingCount >= usedCount; 
             ++usedCount, --unusedCount, currentSum -= digit) {
            if (unusedCount > countRemaining[digit] - remainingCount)
                continue;
            long partialResult = (calculateDFS(digit + 1, currentSum, remainingCount - usedCount) * combination[remainingCount][usedCount]) % MOD;
            result = (result + partialResult * combination[countRemaining[digit] - remainingCount][unusedCount]) % MOD;
        }
        return memo[digit][sum][remainingCount] = result;
    }

    void computePascalTriangle() {
        memset(combination, 0, sizeof(combination));
        combination[0][0] = 1;
        for (int i = 1; i <= 80; ++i) {
            combination[i][0] = 1;
            combination[i][i] = 1;
            for (int j = 1; j < i; ++j)
                combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j]) % MOD;
        }
    }

public:
    int countBalancedPermutations(string num) {
        int totalSum = 0, accumulatedSum = 0, accumulatedCount = 0;
        memset(digitCount, 0, sizeof(digitCount));
        for (char digit : num) {
            totalSum += (digit - '0');
            ++digitCount[digit - '0'];
        }
        if (totalSum & 1)
            return 0;

        computePascalTriangle();
        productMemo[10] = 1;
        for (int digit = 9; digit >= 0; --digit) {
            accumulatedSum += digit * digitCount[digit];
            accumulatedCount += digitCount[digit];
            sumRemaining[digit] = accumulatedSum;
            countRemaining[digit] = accumulatedCount;
            productMemo[digit] = (productMemo[digit + 1] * combination[countRemaining[digit]][digitCount[digit]]) % MOD;
        }
        numDigits = int(num.size());
        memset(memo, -1, sizeof(memo));
        return calculateDFS(0, totalSum >> 1, numDigits >> 1);
    }
};
