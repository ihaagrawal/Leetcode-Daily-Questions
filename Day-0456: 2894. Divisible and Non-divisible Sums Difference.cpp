// 2894. Divisible and Non-divisible Sums Difference (EASY)
// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = n * (n + 1) / 2;
        int k = n / m;
        int divisibleSum = m * (k * (k + 1)) / 2;
        int num1 = totalSum - divisibleSum;
        int num2 = divisibleSum;
        return num1 - num2;
    }
};
