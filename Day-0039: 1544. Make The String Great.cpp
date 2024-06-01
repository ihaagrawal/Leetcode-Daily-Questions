// 1544. Make The String Great (EASY)
// https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty()) {
                char ch = st.top();
                if (abs(ch - c) == 32) {
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }
        string str;
        while (!st.empty()) {
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
};
