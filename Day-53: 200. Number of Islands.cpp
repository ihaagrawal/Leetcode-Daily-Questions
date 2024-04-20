// 200. Number of Islands (MEDIUM)
// https://leetcode.com/problems/number-of-islands/description/?envType=daily-question&envId=2024-04-19

class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]!='1') return;

        grid[i][j]=-1;

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int island=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    island++;
                }
            }
        }
        return island;
    }
};
