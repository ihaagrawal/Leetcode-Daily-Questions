// 2370. Longest Ideal Subsequence (MEDIUM)
// https://leetcode.com/problems/longest-ideal-subsequence/description/?envType=daily-question&envId=2024-04-25

class Solution {
public:
    int longestIdealString(string s, int k) {
        int ans=0;
        vector<int> dp(26, 0);
        int n=s.length();

        for(int i=0;i<n;i++){
            int element=s[i]-'a';

            for(int j=element;j>=0 && j>=element-k;j--){
                if(j==element && dp[j]==0){
                    dp[j]=1;
                    ans=max(ans, dp[element]);
                    continue;
                }
                dp[element] = max(dp[element], dp[j]+1);
            }

            for(int j=element+1;j<26 && j<=element+k;j++){
                dp[element] = max(dp[element], dp[j]+1);
            }

            ans=max(ans, dp[element]);

        }

        return ans;
    }
};
