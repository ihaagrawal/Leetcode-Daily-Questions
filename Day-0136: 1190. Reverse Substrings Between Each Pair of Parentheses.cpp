// 1190. Reverse Substrings Between Each Pair of Parentheses (MEDIUM)
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11


class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        string result = "";

        for(int i=0;i<n;i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                int start = st.top()+1, end = i;
                reverse(s.begin()+start, s.begin()+end);
                st.pop();
            }
        }
        

        for(auto &ch : s){
            if(ch != '(' && ch != ')') result += ch;
        }

        return result;
    }
};
