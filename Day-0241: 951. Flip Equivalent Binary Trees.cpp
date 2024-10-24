// 951. Flip Equivalent Binary Trees (MEDIUM)
// https://leetcode.com/problems/flip-equivalent-binary-trees/description/?envType=daily-question&envId=2024-10-24


class Solution {
public:

    bool solve(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) return true;
        if (!node1 || !node2 || node1->val != node2->val) return false;

        return (solve(node1->left, node2->left) && solve(node1->right, node2->right)) ||
               (solve(node1->left, node2->right) && solve(node1->right, node2->left));
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};
