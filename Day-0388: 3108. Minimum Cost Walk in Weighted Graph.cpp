// 3108. Minimum Cost Walk in Weighted Graph (HARD)
// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/?envType=daily-question&envId=2025-03-20

class Solution {
public:
    int parent[100005];

    int findParent(int node) {
        if (parent[node] == node) 
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionNodes(int node1, int node2) {
        int root1 = parent[node1];
        int root2 = parent[node2];
        parent[root1] = root2;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for (int i = 0; i < n; i++) 
            parent[i] = i;

        for (auto& edge : edges) {
            findParent(edge[0]);
            findParent(edge[1]);
            unionNodes(parent[edge[0]], parent[edge[1]]);
        }

        for (int i = 0; i < n; i++) 
            findParent(i);

        unordered_map<int, int> costMap;
        for (auto& edge : edges) {
            if (!costMap.count(parent[edge[0]])) 
                costMap[parent[edge[0]]] = edge[2];
            else 
                costMap[parent[edge[0]]] &= edge[2];
        }

        vector<int> results;
        for (auto& query : queries) {
            if (parent[query[0]] != parent[query[1]]) 
                results.push_back(-1);
            else 
                results.push_back(costMap[parent[query[0]]]);
        }

        return results;
    }
};
