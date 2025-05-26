// 1857. Largest Color Value in a Directed Graph (HARD)
// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/?envType=daily-question&envId=2025-05-26

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) if (indegree[i] == 0) q.push(i);

        vector<vector<int>> colorCount(n, vector<int>(26, 0));
        int processedNodes = 0;
        int maxColorValue = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processedNodes++;

            colorCount[node][colors[node] - 'a']++;
            maxColorValue = max(maxColorValue, colorCount[node][colors[node] - 'a']);

            for (int neighbor : adj[node]) {
                for (int c = 0; c < 26; ++c) {
                    colorCount[neighbor][c] = max(colorCount[neighbor][c], colorCount[node][c]);
                }
                if (--indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        return processedNodes == n ? maxColorValue : -1;
    }
};
