// 2375. Construct Smallest Number From DI String (MEDIUM)
// https://leetcode.com/problems/construct-smallest-number-from-di-string/description/?envType=daily-question&envId=2025-02-18

class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        stack<int> st;

        for (int i = 0; i <= pattern.size(); ++i) {
            st.push(i + 1);
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        
        return result;
    }
};
