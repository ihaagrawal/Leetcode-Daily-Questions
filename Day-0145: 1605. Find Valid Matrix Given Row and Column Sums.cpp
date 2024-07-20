// 1605. Find Valid Matrix Given Row and Column Sums (MEDIUM)
// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/?envType=daily-question&envId=2024-07-20



class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size(), m=colSum.size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i=0, j=0; i<n && j<m ; i+=(rowSum[i]==0), j+=(colSum[j]==0)){
            int x=min(rowSum[i], colSum[j]);
            matrix[i][j]=x;
            rowSum[i]-=x;
            colSum[j]-=x;
        }
        return matrix;
    }
};
