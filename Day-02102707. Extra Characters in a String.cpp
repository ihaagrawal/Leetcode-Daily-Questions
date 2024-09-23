// 2707. Extra Characters in a String (MEDIUM)
// https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2024-09-23

class Solution {
public:

    int solve(int index, int n, string& s, unordered_set<string>& st, vector<int>& dp){
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];

        string current = "";
        int extra = n;

        for(int i=index;i<n;i++){
            current.push_back(s[i]);
            int curr_extra = (st.find(current) == st.end()) ? current.length() : 0;
            int next = solve(i+1, n, s, st, dp);
            extra = min(extra, curr_extra + next);
        }

        return dp[index] = extra;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> st;
        vector<int> dp(51, -1);

        for(string& word : dictionary) st.insert(word);
        return solve(0, n, s, st, dp);
    }
};
