// 1140. Stone Game II (MEDIUM)
// https://leetcode.com/problems/stone-game-ii/description/?envType=daily-question&envId=2024-08-20

class Solution {
public:

    int solve(int player, int i, int m, int n, vector<int>& piles, vector<vector<vector<int>>>& dp){
        if(i == n) return 0;
        if(dp[player][i][m] != -1) return dp[player][i][m];

        int stone = player == 0 ? 0 : INT_MAX;
        int total = 0;

        for(int j=1;j<= min(2*m, n-i);j++){
            total += piles[i+j-1];
            if(player == 1) 
                stone = min(stone, solve(0, i+j, max(m, j), n, piles, dp));
            else 
                stone = max(stone, total + solve(1, i+j, max(m, j), n, piles, dp));
        }

        return dp[player][i][m] = stone;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return solve(0, 0, 1, n, piles, dp);
    }
};
