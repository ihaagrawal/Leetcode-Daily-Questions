// 684. Redundant Connection (MEDIUM)
// https://leetcode.com/problems/redundant-connection/description/?envType=daily-question&envId=2025-01-29


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), rank(n + 1, 0);

        // Initialize parent array
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        // Find function with path compression
        function<int(int)> find = [&](int node) {
            if (parent[node] != node) {
                parent[node] = find(parent[node]);
            }
            return parent[node];
        };

        // Union function with union by rank
        auto unionSet = [&](int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rootU == rootV) {
                return false; // Cycle detected
            }
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        };

        // Process each edge
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (!unionSet(u, v)) {
                return edge; // Return the edge causing the cycle
            }
        }

        return {};
    }
};
