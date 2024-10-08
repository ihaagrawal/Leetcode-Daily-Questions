// 1963. Minimum Number of Swaps to Make the String Balanced (MEDIUM)
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/?envType=daily-question&envId=2024-10-08


class Solution {
public:
    int minSwaps(string s) {
        int balance = 0, swaps = 0, max_unbalanced = 0;

        for (char c : s) {
            if (c == '[') balance++;
            else balance--;
            if (balance < 0) max_unbalanced = max(max_unbalanced, -balance);
        }

        swaps = (max_unbalanced + 1) / 2;
        return swaps;
    }
};
