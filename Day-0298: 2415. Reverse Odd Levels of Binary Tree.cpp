// 2415. Reverse Odd Levels of Binary Tree (MEDIUM)
// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/?envType=daily-question&envId=2024-12-20


class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodes;
            vector<int> values;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                nodes.push_back(node);
                values.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (level % 2 == 1) {
                reverse(values.begin(), values.end());
                for (int i = 0; i < nodes.size(); ++i) {
                    nodes[i]->val = values[i];
                }
            }

            ++level;
        }

        return root;
    }
};
