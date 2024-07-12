// 1717. Maximum Score From Removing Substrings (MEDIUM)
// https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2024-07-12


class Solution {
public:

    int check(string& s, string str){
        int n = s.length(), count = 0;
        stack<char> st;

        for(int i=0;i<n;i++){
            if(!st.empty() && s[i] == str[1] && st.top() == str[0]){
                st.pop();
                count++;
            }else st.push(s[i]);
        }

        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }

        reverse(s.begin(), s.end());
        return count;
    }

    int maximumGain(string s, int x, int y) {
        string str1 = "", str2 = "";
        if(x < y){
            str1 = "ab";
            str2 = "ba";
            swap(x, y);
        }else{
            str1 = "ba";
            str2 = "ab";
        }

        int points1 = check(s, str2) * x;
        int points2 = check(s, str1) * y;

        return points1 + points2;
    }
};
