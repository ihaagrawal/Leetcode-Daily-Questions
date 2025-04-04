// 1123. Lowest Common Ancestor of Deepest Leaves (MEDIUM)
// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/?envType=daily-question&envId=2025-04-04

class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        if (left.first == right.first) {
            return {left.first + 1, node};
        } else if (left.first > right.first) {
            return {left.first + 1, left.second};
        } else {
            return {right.first + 1, right.second};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};
