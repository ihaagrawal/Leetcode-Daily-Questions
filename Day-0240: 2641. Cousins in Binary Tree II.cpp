// 2641. Cousins in Binary Tree II (MEDIUM)
// https://leetcode.com/problems/cousins-in-binary-tree-ii/description/?envType=daily-question&envId=2024-10-23


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        updateValues(vector<TreeNode*>{root});
        return root;
    }

private:
    void updateValues(vector<TreeNode*> currentLevel) {
        if (currentLevel.empty()) return;

        int totalValue = 0;
        for (auto node : currentLevel) {
            if (!node) continue;
            if (node->left) totalValue += node->left->val;
            if (node->right) totalValue += node->right->val;
        }

        vector<TreeNode*> nextLevel;
        for (auto node : currentLevel) {
            int siblingValue = 0;
            if (node->left) siblingValue += node->left->val;
            if (node->right) siblingValue += node->right->val;

            if (node->left) {
                node->left->val = totalValue - siblingValue;
                nextLevel.push_back(node->left);
            }
            if (node->right) {
                node->right->val = totalValue - siblingValue;
                nextLevel.push_back(node->right);
            }
        }

        updateValues(nextLevel);
    }
};
