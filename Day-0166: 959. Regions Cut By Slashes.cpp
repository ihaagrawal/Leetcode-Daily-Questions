// 959. Regions Cut By Slashes (MEDIUM)
// https://leetcode.com/problems/regions-cut-by-slashes/description/?envType=daily-question&envId=2024-08-10

class Solution {
public:

    void dfs(vector<vector<int>>& binary, int i, int j){
        vector<int> x = {1, 0, -1, 0};
        vector<int> y = {0, 1, 0, -1};

        if(i < 0 || i >= binary.size() || j < 0 || j >= binary.size() || binary[i][j] == 1) return;
        binary[i][j] = 1;

        for(int k=0;k<4;k++){
            int ni = i + x[k];
            int nj = j + y[k];
            dfs(binary, ni, nj);
        }
    }

    void filling(vector<vector<int>> &arr,int i, vector<vector<int>>& binary){
        for(int k=0;k<3;k++){
            binary[i].push_back(arr[0][k]); 
            binary[i+1].push_back(arr[1][k]); 
            binary[i+2].push_back(arr[2][k]);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size(), m= grid[0].size();
        vector<vector<int>> empty{{0,0,0}, {0,0,0}, {0,0,0}};
        vector<vector<int>> forward{{0,0,1}, {0,1,0}, {1,0,0}};
        vector<vector<int>> backward{{1,0,0}, {0,1,0}, {0,0,1}};
        vector<vector<int>> binary(grid.size() * 3);

        int ind = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == ' ') filling(empty, ind, binary);
                else if(grid[i][j] == '/') filling(forward, ind, binary);
                else filling(backward, ind, binary);
            }
            ind += 3;
        }

        int result = 0;
        for(int i=0;i<binary.size();i++){
            for(int j=0;j<binary[0].size();j++){
                if(binary[i][j] == 0){
                    dfs(binary, i, j);
                    result++;
                }
            }
        }

        return result;
    }
};
