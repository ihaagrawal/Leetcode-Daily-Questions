// 1038. Binary Search Tree to Greater Sum Tree (MEDIUM)
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/?envType=daily-question&envId=2024-06-25

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
    void fun(TreeNode* root, int &sum)
    {
        if(root==NULL) return;

        fun(root->right, sum);
        sum+=root->val;
        root->val = sum;
        fun(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        fun(root, sum);

        return root;
    }
};
