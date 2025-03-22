// 2685. Count the Number of Complete Components (MEDIUM)
// https://leetcode.com/problems/count-the-number-of-complete-components/description/?envType=daily-question&envId=2025-03-22

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int completeComponents = 0;

        function<void(int, vector<int>&)> dfs = [&](int node, vector<int>& component) {
            visited[node] = true;
            component.push_back(node);
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, component);
                }
            }
        };

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, component);

                int size = component.size();
                int edgesCount = 0;

                for (int node : component) {
                    edgesCount += adj[node].size();
                }

                edgesCount /= 2;

                if (edgesCount == size * (size - 1) / 2) {
                    ++completeComponents;
                }
            }
        }

        return completeComponents;
    }
};
