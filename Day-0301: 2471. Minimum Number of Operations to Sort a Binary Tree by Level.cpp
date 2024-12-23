// 2471. Minimum Number of Operations to Sort a Binary Tree by Level (MEDIUM)
// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/?envType=daily-question&envId=2024-12-23


class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            totalSwaps += calculateMinSwaps(levelValues);
        }

        return totalSwaps;
    }

private:
    int calculateMinSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arrWithIndex(n);

        for (int i = 0; i < n; ++i) {
            arrWithIndex[i] = {nums[i], i};
        }

        sort(arrWithIndex.begin(), arrWithIndex.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || arrWithIndex[i].second == i) {
                continue;
            }

            int cycleLength = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arrWithIndex[j].second;
                ++cycleLength;
            }

            if (cycleLength > 1) {
                swaps += (cycleLength - 1);
            }
        }

        return swaps;
    }
};
