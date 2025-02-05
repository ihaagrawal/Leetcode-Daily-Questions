// 1790. Check if One String Swap Can Make Strings Equal (EASY)
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        if(s1 == s2) return true;
        if(n == 1) return false;
        
        if(n == 2){
            if(s1[0] != s2[1] || s1[1] != s2[0]) return false;
        }

        int count = 0;
        char ch1 = ' ', ch2 = ' ';
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                count++;
                if(ch1 == ' ' && ch2 == ' '){
                    ch1 = s1[i];
                    ch2 = s2[i];
                }else{
                    if(ch1 != s2[i] || ch2 != s1[i]) return false;
                }
            }

            if(count > 2) return false;
        }

        if(count != 2) return false;
        return true;
    }
};
