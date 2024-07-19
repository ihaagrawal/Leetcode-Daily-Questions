// 1380. Lucky Numbers in a Matrix (EASY)
// https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19


class Solution {
public:

    bool check(vector<vector<int>>& matrix, int row, int col, int p) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][col] > p) {
                return false;
            }
        }
        return true;
    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> result;

        for(int i=0;i<n;i++){
            int num = INT_MAX, num2;
            for(int j=0;j<m;j++){
                if(matrix[i][j] < num){
                    num2 = j;
                    num = matrix[i][j];
                }
            }
            if (check(matrix, i, num2, num) == true) result.push_back(num);
        }

        return result;
    }
};
