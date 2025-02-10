// 3174. Clear Digits (EASY)
// https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10

class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();

        stack<char> st;
        for(int i=0; i<n; i++) {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                st.push(s[i]);
            } else if(s[i] >= '0' && s[i] <= '9') {
                if(st.empty()) continue;
                else st.pop();
            }
        }

        string result = "";
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
