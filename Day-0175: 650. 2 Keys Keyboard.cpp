// 650. 2 Keys Keyboard (MEDIUM)
// https://leetcode.com/problems/2-keys-keyboard/description/?envType=daily-question&envId=2024-08-19

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        
        vector<int> dp(n + 1, 0);
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;  
            for (int j = i / 2; j > 0; --j) {
                if (i % j == 0) {  
                    dp[i] = dp[j] + (i / j);
                    break;  
                }
            }
        }
        
        return dp[n];
    }
};
