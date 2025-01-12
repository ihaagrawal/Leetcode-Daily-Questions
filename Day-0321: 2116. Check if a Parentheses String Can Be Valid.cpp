// 2116. Check if a Parentheses String Can Be Valid (MEDIUM)
// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/?envType=daily-question&envId=2025-01-12


class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false; 

        int open = 0, close = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0' || s[i] == '(') open++;
            else close++;
            if (close > open) return false; 
        }

        open = 0, close = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0' || s[i] == ')') close++;
            else open++;
            if (open > close) return false; 
        }

        return true;
    }
};
