// 1545. Find Kth Bit in Nth Binary String (MEDIUM)
// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/


class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int length = (1 << n) - 1;
        int mid = length / 2 + 1;
        if (k == mid) return '1';
        if (k < mid) return findKthBit(n - 1, k);
        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};
