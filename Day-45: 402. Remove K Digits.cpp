// 402. Remove K Digits (MEDIUM)
// https://leetcode.com/problems/remove-k-digits/description/?envType=daily-question&envId=2024-04-11

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        if(n==k) return "0";
        vector<char> st;
        for(int i=0; i<n; ++i){
            while(k>0 && !st.empty() && st.back()>num[i]){
                st.pop_back();
                --k;
            }
            st.push_back(num[i]);
        }        
        while(k-->0) st.pop_back();
        
        string result;
        for(char c: st){
            if(c=='0' && result.empty()) continue;
            result += c;
        }
        return result.empty() ? "0" : result;
    }
};
