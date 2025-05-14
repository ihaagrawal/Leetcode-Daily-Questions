// 3337. Total Characters in String After Transformations II (HARD)
// https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/?envType=daily-question&envId=2025-05-14

class Solution {
public:
    static const int mod = 1e9 + 7;
    static const int alphabet = 26;

    vector<vector<int>> multiply(const vector<vector<int>>& a, const vector<vector<int>>& b) {
        vector<vector<int>> result(alphabet, vector<int>(alphabet, 0));
        for (int i = 0; i < alphabet; ++i) {
            for (int k = 0; k < alphabet; ++k) {
                if (a[i][k]) {
                    for (int j = 0; j < alphabet; ++j) {
                        result[i][j] = (result[i][j] + (long long)a[i][k] * b[k][j]) % mod;
                    }
                }
            }
        }
        return result;
    }

    vector<vector<int>> power(vector<vector<int>> matrix, int exp) {
        vector<vector<int>> identity(alphabet, vector<int>(alphabet, 0));
        for (int i = 0; i < alphabet; ++i) {
            identity[i][i] = 1;
        }
        while (exp > 0) {
            if (exp & 1) {
                identity = multiply(identity, matrix);
            }
            matrix = multiply(matrix, matrix);
            exp >>= 1;
        }
        return identity;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<int>> transition(alphabet, vector<int>(alphabet, 0));
        for (int c = 0; c < alphabet; ++c) {
            for (int shift = 1; shift <= nums[c]; ++shift) {
                transition[(c + shift) % alphabet][c] += 1;
            }
        }

        vector<vector<int>> transition_power = power(transition, t);
        vector<int> frequency(alphabet, 0);
        for (char ch : s) {
            frequency[ch - 'a']++;
        }

        long long result = 0;
        for (int col = 0; col < alphabet; ++col) {
            long long column_sum = 0;
            for (int row = 0; row < alphabet; ++row) {
                column_sum = (column_sum + transition_power[row][col]) % mod;
            }
            result = (result + frequency[col] * column_sum) % mod;
        }

        return (int)result;
    }
};
