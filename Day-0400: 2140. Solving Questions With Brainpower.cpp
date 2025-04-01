// 2140. Solving Questions With Brainpower (MEDIUM)
// https://leetcode.com/problems/solving-questions-with-brainpower/description/?envType=daily-question&envId=2025-04-01


class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);
        
        for(int i=n-1;i>=0;i--){
            int point = questions[i][0], brain = questions[i][1];
            long long take = point + dp[min(i + brain + 1, n)];
            long long notTake = dp[i+1];
            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};



















// class Solution {
// public:

//     long long solve(int i, int n, vector<vector<int>>& questions, vector<long long>& dp){
//         if(i >= n) return 0;
//         int point = questions[i][0], brain = questions[i][1];
//         if(dp[i] != -1) return dp[i];

//         long long take = point + solve(i + brain + 1, n, questions, dp);
//         long long notTake = solve(i+1, n, questions, dp);
        
//         return dp[i] = max(take, notTake);
//     }

//     long long mostPoints(vector<vector<int>>& questions) {
//         int n = questions.size();
//         vector<long long> dp(n, -1);
//         return solve(0, n, questions, dp);
//     }
// };
