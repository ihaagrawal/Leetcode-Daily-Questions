// 1092. Shortest Common Supersequence  (HARD)
// https://leetcode.com/problems/shortest-common-supersequence/description/?envType=daily-question&envId=2025-02-28


class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        
        // Step 1: Find the LCS
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Construct the shortest common supersequence
        string result;
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                // Common character in LCS
                result += str1[i - 1];
                --i;
                --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                // Character from str1
                result += str1[i - 1];
                --i;
            } else {
                // Character from str2
                result += str2[j - 1];
                --j;
            }
        }

        // Add remaining characters
        while (i > 0) {
            result += str1[i - 1];
            --i;
        }
        while (j > 0) {
            result += str2[j - 1];
            --j;
        }

        // Reverse the result since we constructed it backwards
        reverse(result.begin(), result.end());
        return result;
    }
};
