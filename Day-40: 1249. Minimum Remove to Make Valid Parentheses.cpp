// 1249. Minimum Remove to Make Valid Parentheses (MEDIUM)
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=daily-question&envId=2024-04-06

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int braces=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') braces++;
            else if(s[i]==')'){
                if(braces>0) braces--;
                else s[i]='$';
            }
        }

        for(int i=s.length()-1;i>=0 && braces>0;i--){
            if(s[i]=='('){
                s[i]='$';
                braces--;
            }
            
        }

        string result;
        for(int i=0;i<s.length();i++){
            if(s[i]!='$')
                result += s[i];
        }
        return result;
    }
};
