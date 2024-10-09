// 921. Minimum Add to Make Parentheses Valid (MEDIUM)
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=daily-question&envId=2024-10-09


class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;

        for (char c : s) {
            if (c == '(') open++;
            else {
                if (open > 0) open--;
                else close++;
            }
        }

        return open + close;
    }
};
