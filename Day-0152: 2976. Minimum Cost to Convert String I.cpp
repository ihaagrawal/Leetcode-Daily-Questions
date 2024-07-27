// 2976. Minimum Cost to Convert String I (MEDIUM)
// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2024-07-27


class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long matrix[26][26];
        for(int i=0;i<26;i++){
            fill(matrix[i], matrix[i]+26, LLONG_MAX);
            matrix[i][i] = 0;
        }

        for(int i=0;i<original.size();i++){
            int num1 = original[i] - 'a', num2 = changed[i] - 'a';
            matrix[num1][num2] = min(matrix[num1][num2], (long long)cost[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(matrix[i][k] != LLONG_MAX && matrix[k][j] != LLONG_MAX){
                        matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                    }
                }
            }
        }

        long long result = 0;
        for(int i=0;i<source.size();i++){
            int num1 = source[i] - 'a', num2 = target[i] - 'a';
            if(num1 == num2) continue;
            if(matrix[num1][num2] == LLONG_MAX) return -1;
            else{
                if(result > LLONG_MAX - matrix[num1][num2]) return -1;
                result += matrix[num1][num2];
            }
        }

        return result;
    }
};
