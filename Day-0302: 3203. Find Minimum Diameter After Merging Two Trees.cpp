// 3203. Find Minimum Diameter After Merging Two Trees (HARD)
// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/?envType=daily-question&envId=2024-12-24


class Solution {
public:
    static int diameter(vector<vector<int>>& connections) {
        int nodeCount = connections.size() + 1;
        vector<int> degrees(nodeCount, 0);
        vector<vector<int>> adjacencyList(nodeCount);
        for (auto& connection : connections) {
            int node1 = connection[0], node2 = connection[1];
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
            degrees[node1]++;
            degrees[node2]++;
        }

        queue<int> leaves;
        for (int i = 0; i < nodeCount; i++) {
            if (degrees[i] == 1) {
                leaves.push(i);
            }
        }

        int depth = 0, remainingNodes = nodeCount;
        while (remainingNodes > 2) {
            int leafCount = leaves.size();
            remainingNodes -= leafCount;
            for (int i = 0; i < leafCount; i++) {
                int currentNode = leaves.front();
                leaves.pop();
                for (int neighbor : adjacencyList[currentNode]) {
                    if (--degrees[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
            depth++;
        }

        return (remainingNodes == 2) ? 2 * depth + 1 : 2 * depth;
    }

    static int minimumDiameterAfterMerge(vector<vector<int>>& connections1, vector<vector<int>>& connections2) {
        int diameter1 = diameter(connections1);
        int diameter2 = diameter(connections2);
        return max({diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1});
    }
};
