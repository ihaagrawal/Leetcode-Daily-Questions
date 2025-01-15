// 2429. Minimize XOR (MEDIUM)
// https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15


class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num2SetBits = __builtin_popcount(num2);
        int result = 0;

        for (int i = 31; i >= 0 && num2SetBits > 0; --i) {
            if (num1 & (1 << i)) {
                result |= (1 << i);
                --num2SetBits;
            }
        }

        for (int i = 0; i < 32 && num2SetBits > 0; ++i) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                --num2SetBits;
            }
        }

        return result;
    }
};
