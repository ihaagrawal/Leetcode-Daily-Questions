// 678. Valid Parenthesis String (MEDIUM)
// https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2024-04-07

class Solution {
public:
    bool checkValidString(string s) {
        int open=0, closed=0, star=0;
        for(char c:s){
            if(c=='(') open++;
            else if(c==')'){
                if(open>0) open--;
                else if(star>0) star--;
                else return false;
            }
            else if(c=='*') star++;
        }

        star=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')') closed++;
            else if(s[i]=='('){
                if(closed>0) closed--;
                else if(star>0) star--;
                else return false;
            }
            else if(s[i]=='*') star++;
        }

        return true;
    }
};
