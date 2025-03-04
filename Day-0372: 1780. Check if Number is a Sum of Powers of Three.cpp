// 1780. Check if Number is a Sum of Powers of Three (MEDIUM)
// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 > 1) return false;
            n /= 3;
        }
        return true;
    }
};
