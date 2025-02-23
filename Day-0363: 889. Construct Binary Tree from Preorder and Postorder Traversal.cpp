// 889. Construct Binary Tree from Preorder and Postorder Traversal (MEDIUM)
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2025-02-23

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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return buildTree(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, 
                        int preStart, int preEnd, int postStart, int postEnd) {
        if (preStart > preEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        if (preStart == preEnd) return root;

        int leftRootVal = preorder[preStart + 1];
        int leftRootIndexInPost = postStart;
        while (postorder[leftRootIndexInPost] != leftRootVal) {
            leftRootIndexInPost++;
        }

        int leftSubtreeSize = leftRootIndexInPost - postStart + 1;

        root->left = buildTree(preorder, postorder, 
                               preStart + 1, preStart + leftSubtreeSize, 
                               postStart, leftRootIndexInPost);

        root->right = buildTree(preorder, postorder, 
                                preStart + leftSubtreeSize + 1, preEnd, 
                                leftRootIndexInPost + 1, postEnd - 1);

        return root;
    }
};
