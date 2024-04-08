// 58. Length of Last Word (EASY)
// https://leetcode.com/problems/length-of-last-word/description/?envType=daily-question&envId=2024-04-01

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.length(), count=0;
        int i=len-1;
        while(s[i]==' ' && i>=0)
            i--;
        while(i>=0 && s[i]!=' '){
            count++;
            i--;
        }
            
        return count;
    }
};
