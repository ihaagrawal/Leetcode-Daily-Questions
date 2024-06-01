// 1137. N-th Tribonacci Number (EASY)
// https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24

class Solution {
public:
    int tribonacci(int n) {
        unordered_map<int, int> memo;
        return tribonacciHelper(n, memo);
    }

private:
    int tribonacciHelper(int n, unordered_map<int, int>& memo) {
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        if (n <= 1) return n;
        if (n == 2) return 1;

        int result = tribonacciHelper(n - 1, memo) + tribonacciHelper(n - 2, memo) + tribonacciHelper(n - 3, memo);
        memo[n] = result;
        return result;
    }
};
