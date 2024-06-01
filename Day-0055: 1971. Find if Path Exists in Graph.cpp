// 1971. Find if Path Exists in Graph (EASY)
// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

class Solution {
public:

    void dfs(bool& found, int node, int destination, vector<int> adj[], vector<bool>& visited){
        visited[node]=true;
        if(node==destination){
            found=true;
            return;
        }
        for(auto j:adj[node]){
            if(!visited[j]){
                dfs(found, j, destination, adj, visited);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        bool found=false;
        vector<int> adj[n];
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(found, source, destination, adj, visited);
        return found;
    }
};
