// 2467. Most Profitable Path in a Tree (MEDIUM)
// https://leetcode.com/problems/most-profitable-path-in-a-tree/description/?envType=daily-question&envId=2025-02-24


class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(), maxIncome = INT_MIN;
        vector<vector<int>> tree(n);
        vector<bool> visited(n, false);

        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        vector<int> bobPath(n, -1);
        findBobPath(tree, visited, bobPath, bob, 0);

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        visited.assign(n, false);

        while (!q.empty()) {
            auto [node, time, income] = q.front();
            q.pop();

            if (bobPath[node] == -1 || time < bobPath[node]) {
                income += amount[node];
            } else if (time == bobPath[node]) {
                income += amount[node] / 2;
            }

            if (tree[node].size() == 1 && node != 0) {
                maxIncome = max(maxIncome, income);
            }

            for (int neighbor : tree[node]) {
                if (!visited[neighbor]) {
                    q.push({neighbor, time + 1, income});
                }
            }

            visited[node] = true;
        }

        return maxIncome;
    }

private:
    bool findBobPath(const vector<vector<int>>& tree, vector<bool>& visited, vector<int>& bobPath, int node, int time) {
        visited[node] = true;
        bobPath[node] = time;

        if (node == 0) return true;

        for (int neighbor : tree[node]) {
            if (!visited[neighbor]) {
                if (findBobPath(tree, visited, bobPath, neighbor, time + 1)) {
                    return true;
                }
            }
        }

        bobPath[node] = -1;
        return false;
    }
};
