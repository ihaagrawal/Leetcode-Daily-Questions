// 1593. Split a String Into the Max Number of Unique Substrings (MEDIUM)
// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21


class Solution {
public:

    int solve(string s, int i, int n, unordered_set<string>mp){
        if(i >= n) return 0;
        int count = 0;
        
        for(int j=i+1;j<=n;j++){
            string str = s.substr(i, j-i);
            if(mp.find(str) == mp.end()){
                mp.insert(str);
                count = max(count, 1 + solve(s, j, n, mp));
                mp.erase(str);
            }
        }

        return count;
    }

    int maxUniqueSplit(string s) {
        int n = s.size();
        unordered_set<string> mp;
        return solve(s, 0, n, mp);
    }
};
