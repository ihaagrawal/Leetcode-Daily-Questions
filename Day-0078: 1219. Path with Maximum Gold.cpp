// 1219. Path with Maximum Gold (MEDIUM)
// https://leetcode.com/problems/path-with-maximum-gold/description/?envType=daily-question&envId=2024-05-14

class Solution {
public:

    vector<int> row = {1, 0, -1, 0};
    vector<int> col = {0, 1, 0, -1};

    int DFS(vector<vector<int>>& grid, int i, int j, int n, int m){

        if(i>=n || i<0 || j>=m || j<0 || grid[i][j]==0) return 0;

        int originalGold = grid[i][j];
        grid[i][j] = 0;

        int maxGold = 0;
        for(int k=0;k<4;k++){
            int new_i = i + row[k];
            int new_j = j + col[k];

            maxGold = max(maxGold, DFS(grid, new_i, new_j, n, m));
        }

        grid[i][j] = originalGold;
        return maxGold + originalGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        int maxGold=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    maxGold = max(maxGold, DFS(grid, i, j, n, m));
                }
            }
        }

        return maxGold;
    }
};
