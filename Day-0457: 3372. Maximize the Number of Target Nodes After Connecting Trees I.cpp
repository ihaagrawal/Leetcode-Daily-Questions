// 3372. Maximize the Number of Target Nodes After Connecting Trees I (MEDIUM)
// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/?envType=daily-question&envId=2025-05-28

class Solution {
public:
    vector<vector<int>> buildAdjList(const vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }
    
    int dfs(const vector<vector<int>>& adj, int node, int parent, int steps) {
        if (steps < 0) return 0;
        int count = 1;
        for (int neighbor : adj[node]) {
            if (neighbor != parent) 
                count += dfs(adj, neighbor, node, steps - 1);
        }
        return count;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        auto adj1 = buildAdjList(edges1), adj2 = buildAdjList(edges2);
        int n = adj1.size(), m = adj2.size(), maxB = 0;
        vector<int> res(n);

        for (int i = 0; i < m; i++) maxB = max(maxB, dfs(adj2, i, -1, k - 1));
        for (int i = 0; i < n; i++) res[i] = dfs(adj1, i, -1, k) + maxB;
        return res;
    }
};
