// 140. Word Break II (HARD)
// https://leetcode.com/problems/word-break-ii/description/?envType=daily-question&envId=2024-05-25

class Solution {
public:

    void solve(string s, int ind, unordered_set<string>& st, string current, vector<string>& result){
        if(ind==s.length()){
            result.push_back(current);
            return;
        }

        string t = "";
        for(int i=ind;i<s.size();i++){
            t += s[i];
            if(st.find(t)!=st.end()){
                solve(s, i+1, st, current+t+(i<s.length()-1?" ":""), result);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        solve(s, 0, st, "", result);
        return result;
    }
};
