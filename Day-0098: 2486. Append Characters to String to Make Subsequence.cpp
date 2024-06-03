// 2486. Append Characters to String to Make Subsequence (MEDIUM)
// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(), m = t.size();
        int j = 0;
        for(int i=0;i<n;i++){
            if(j < m && s[i] == t[j]){
                j++;
            }
        }
        return m - j;
    }
};
