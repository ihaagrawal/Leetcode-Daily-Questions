// 2872. Maximum Number of K-Divisible Components (HARD)
// https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/?envType=daily-question&envId=2024-12-21


class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);
        int result = 0;

        function<long long(int)> dfs = [&](int node) {
            visited[node] = 1;
            long long sum = values[node];
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    long long subSum = dfs(neighbor);
                    if (subSum % k == 0) result++;
                    else sum += subSum;
                }
            }
            return sum;
        };

        if (dfs(0) % k == 0) result++;
        return result;
    }
};
