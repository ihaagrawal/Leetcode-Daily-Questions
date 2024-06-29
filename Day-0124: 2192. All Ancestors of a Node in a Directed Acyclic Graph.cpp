// 2192. All Ancestors of a Node in a Directed Acyclic Graph (MEDIUM)
// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/?envType=daily-question&envId=2024-06-29


class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>(0));
        vector<int> indeg(n, 0);

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i] == 0) q.push(i);
        }

        vector<unordered_set<int>> ancestors(n);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int adjnode : adj[u]){
                indeg[adjnode]--;
                ancestors[adjnode].insert(u);
                for(int ancestor : ancestors[u]){
                    ancestors[adjnode].insert(ancestor);
                }

                if(indeg[adjnode] == 0) q.push(adjnode);
            }
        }

        vector<vector<int>> result(n);
        for(int i = 0; i < n; i++){
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
};
