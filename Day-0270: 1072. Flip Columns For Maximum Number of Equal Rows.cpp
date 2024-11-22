// 1072. Flip Columns For Maximum Number of Equal Rows (MEDIUM)
// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/?envType=daily-question&envId=2024-11-22


class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<string, int> mp;

        for(int i=0;i<n;i++){
            string str;
            if(matrix[i][0] == 1){
                for(int j=0;j<m;j++){
                    matrix[i][j] = !matrix[i][j];
                }
            }
            for(int j=0;j<m;j++){
                str += to_string(matrix[i][j]);
            }    
            mp[str]++;
        }

        int count = 0;
        for(auto it : mp){
            count = max(count, it.second);
        }

        return count;
    }
};
