// 2220. Minimum Bit Flips to Convert Number (EASY)
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=daily-question&envId=2024-09-11

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = start^goal, count = 0;
        while(result){
            count += result & 1;
            result >>= 1;
        }
        return count;
    }
};
