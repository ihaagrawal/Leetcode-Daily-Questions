// 834. Sum of Distances in Tree (HARD)
// https://leetcode.com/problems/sum-of-distances-in-tree/description/?envType=daily-question&envId=2024-04-28

class Solution {
public:
    void dfs(int node, int parent, vector<int>& count, vector<int>& result, vector<vector<int>>& adj) {
        count[node] = 1;
        result[node] = 0;

        for (int child : adj[node]) {
            if (child != parent) {
                dfs(child, node, count, result, adj);
                count[node] += count[child];
                result[node] += result[child] + count[child];
            }
        }
    }

    void dfs2(int node, int parent, int n, vector<int>& count, vector<int>& result, vector<vector<int>>& adj) {
        for (int child : adj[node]) {
            if (child != parent) {
                result[child] = result[node] - count[child] + (n - count[child]);
                dfs2(child, node, n, count, result, adj);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> count(n, 0);
        vector<int> result(n, 0);

        dfs(0, -1, count, result, adj);
        dfs2(0, -1, n, count, result, adj);

        return result;
    }
};
