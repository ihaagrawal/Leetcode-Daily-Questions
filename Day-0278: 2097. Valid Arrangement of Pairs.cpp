// 2097. Valid Arrangement of Pairs (HARD)
// https://leetcode.com/problems/valid-arrangement-of-pairs/description/?envType=daily-question&envId=2024-11-30


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> outDegree, inDegree;

        for (const auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            graph[start].push_back(end);
            outDegree[start]++;
            inDegree[end]++;
        }

        int startNode = pairs[0][0];
        for (const auto& [node, _] : graph) {
            if (outDegree[node] - inDegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        vector<int> eulerPath;
        stack<int> stk;
        stk.push(startNode);

        while (!stk.empty()) {
            int curr = stk.top();
            if (!graph[curr].empty()) {
                int next = graph[curr].back();
                graph[curr].pop_back();
                stk.push(next);
            } else {
                eulerPath.push_back(curr);
                stk.pop();
            }
        }

        reverse(eulerPath.begin(), eulerPath.end());
        vector<vector<int>> result;
        for (size_t i = 0; i < eulerPath.size() - 1; ++i) {
            result.push_back({eulerPath[i], eulerPath[i + 1]});
        }

        return result;
    }
};
