// 514. Freedom Trail (HARD)
// https://leetcode.com/problems/freedom-trail/description/?envType=daily-question&envId=2024-04-27

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m=ring.size(), n=key.size();
        vector<vector<bool>> visited(m, vector<bool>(n+1, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=true;
        int depth=0;

        while(!q.empty()){
            for(int k=q.size();k>0;k--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(j==n) return depth; 

                if(ring[i]==key[j]){
                    if(!visited[i][j+1]){
                        q.push({i,j+1});
                        visited[i][j+1]=true;
                    }
                }else{
                    if(!visited[(i-1+m)%m][j]){
                        visited[(i-1+m)%m][j]=true;
                        q.push({(i-1+m)%m, j});
                    }
                    if(!visited[(i+1)%m][j]){
                        visited[(i+1)%m][j]=true;
                        q.push({(i+1)%m, j});
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};
