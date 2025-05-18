// 1931. Painting a Grid With Three Different Colors (HARD)
// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/?envType=daily-question&envId=2025-05-18

#include <vector>
#include <cmath>
using namespace std;

// Helper function to generate all valid patterns for a column
vector<int> generateValidPatterns(int m) {
    vector<int> patterns;
    int maxPattern = pow(3, m); // 3^m possible patterns
    for (int p = 0; p < maxPattern; ++p) {
        vector<int> colors;
        int num = p;
        bool isValid = true;
        for (int i = 0; i < m; ++i) {
            int color = num % 3; // Extract current cell's color
            if (!colors.empty() && colors.back() == color) {
                isValid = false; // Adjacent cells have the same color
                break;
            }
            colors.push_back(color);
            num /= 3;
        }
        if (isValid) patterns.push_back(p);
    }
    return patterns;
}

// Helper function to check compatibility between two patterns
bool areCompatible(int p1, int p2, int m) {
    for (int i = 0; i < m; ++i) {
        if ((p1 % 3) == (p2 % 3)) return false; // Same color in the same row
        p1 /= 3;
        p2 /= 3;
    }
    return true;
}

class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;

        // Generate valid patterns
        vector<int> validPatterns = generateValidPatterns(m);
        int numPatterns = validPatterns.size();

        // Precompute compatibility between patterns
        vector<vector<bool>> compatible(numPatterns, vector<bool>(numPatterns, false));
        for (int i = 0; i < numPatterns; ++i) {
            for (int j = 0; j < numPatterns; ++j) {
                compatible[i][j] = areCompatible(validPatterns[i], validPatterns[j], m);
            }
        }

        // DP array
        vector<vector<int>> dp(n, vector<int>(numPatterns, 0));
        for (int i = 0; i < numPatterns; ++i) dp[0][i] = 1;

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < numPatterns; ++i) {
                for (int k = 0; k < numPatterns; ++k) {
                    if (compatible[i][k]) {
                        dp[j][i] = (dp[j][i] + dp[j-1][k]) % MOD;
                    }
                }
            }
        }

        // Sum up all ways for the last column
        int result = 0;
        for (int i = 0; i < numPatterns; ++i) {
            result = (result + dp[n-1][i]) % MOD;
        }

        return result;
    }
};
