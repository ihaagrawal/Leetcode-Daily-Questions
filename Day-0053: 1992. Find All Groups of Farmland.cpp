// 1992. Find All Groups of Farmland (MEDIUM)
// https://leetcode.com/problems/find-all-groups-of-farmland/description/?envType=daily-question&envId=2024-04-20

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& maxRow, int& maxCol){
        int m=grid.size(), n=grid[0].size();
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]!=1) return;

        grid[i][j]=-1;
        maxRow = max(maxRow, i);
        maxCol = max(maxCol, j);

        dfs(grid, i+1, j, maxRow, maxCol);
        dfs(grid, i-1, j, maxRow, maxCol);
        dfs(grid, i, j+1, maxRow, maxCol);
        dfs(grid, i, j-1, maxRow, maxCol);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size(), n=land[0].size();
        vector<vector<int>> result;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1){
                    int maxRow = i, maxCol = j;
                    dfs(land, i, j, maxRow, maxCol);
                    result.push_back({i, j, maxRow, maxCol});
                }
            }
        }
        return result;
    }
};
