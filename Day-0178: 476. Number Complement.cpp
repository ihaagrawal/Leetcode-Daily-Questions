// 476. Number Complement (EASY)
// https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22


class Solution {
public:
    int findComplement(int num) {
        int mask = 0;
        int temp = num;
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        
        return num ^ mask;
    }
};
