// 2825. Make String a Subsequence Using Cyclic Increments (MEDIUM)
// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/?envType=daily-question&envId=2024-12-04


class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int n1 = str1.size(), n2 = str2.size();
        
        while (i < n1 && j < n2) {
            char nextChar = (str1[i] == 'z') ? 'a' : str1[i] + 1;
            if (str1[i] == str2[j] || nextChar == str2[j]) j++;
            i++;
        }
        
        return j == n2;
    }
};
