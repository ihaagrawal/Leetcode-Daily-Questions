// 3133. Minimum Array End (MEDIUM)
// https://leetcode.com/problems/minimum-array-end/description/?envType=daily-question&envId=2024-11-09

class Solution {
public:
    long minEnd(int n, int x) {
        long res = x, rem = n - 1, pos = 1;
        
        while (rem) {
            if (!(x & pos)) {
                res |= (rem & 1) * pos;
                rem >>= 1;
            }
            pos <<= 1;
        }
        
        return res;
    }
};
