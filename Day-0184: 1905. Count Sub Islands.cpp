// 1905. Count Sub Islands (MEDIUM)
// https://leetcode.com/problems/count-sub-islands/description/?envType=daily-question&envId=2024-08-28

class Solution {
public:

    const int dir[5]={0,1,0,-1,0};

    inline bool outside(int i, int j, int n, int m){
        return i<0 ||i>=n||j<0 || j>=m;
    }

    bool dfs(int i, int j, int mark, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n, int m){
        if(grid1[i][j] != 1) return 0;
        grid2[i][j] = mark;

        bool sub = 1;
        for(int k=0;k<4;k++){
            int i1 = i + dir[k], j1 = j + dir[k+1];
            if(outside(i1, j1, n, m) || grid2[i1][j1] != 1) continue;
            if(grid1[i1][j1] != 1) sub = 0;
            if(!dfs(i1, j1, mark, grid1, grid2, n, m)) sub = 0;
        }

        return sub;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        int count = 0, mark = 2;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j] == 1){
                    count += dfs(i, j, mark++, grid1, grid2, n, m);
                }
            }
        }

        return count;
    }
};
