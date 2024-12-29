// 1639. Number of Ways to Form a Target String Given a Dictionary (HARD)
// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/?envType=daily-question&envId=2024-12-29


#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#define MOD 1000000007

class Solution {
public:
    int numWays(std::vector<std::string>& words, std::string target) {
        int m = target.size();
        int n = words[0].size();
        
        std::vector<std::vector<int>> freq(26, std::vector<int>(n, 0));
        for (const auto& word : words) {
            for (int j = 0; j < n; ++j) {
                freq[word[j] - 'a'][j]++;
            }
        }
        
        std::vector<std::vector<long long>> dp(m + 1, std::vector<long long>(n + 1, 0));
        
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 1;
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1];
                if (freq[target[i - 1] - 'a'][j - 1] > 0) {
                    dp[i][j] += dp[i - 1][j - 1] * freq[target[i - 1] - 'a'][j - 1];
                    dp[i][j] %= MOD;
                }
            }
        }
        
        return dp[m][n];
    }
};
