// 979. Distribute Coins in Binary Tree (MEDIUM)
// https://leetcode.com/problems/distribute-coins-in-binary-tree/description/?envType=daily-question&envId=2024-05-18

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

    int distribute(TreeNode* root, int& moves){
        if(!root) return 0;
        int left = distribute(root->left, moves);
        int right = distribute(root->right, moves);
        moves += abs(left) + abs(right);
        return (left+right+root->val) - 1;
    }

    int distributeCoins(TreeNode* root) {
        int moves = 0;
        distribute(root, moves);
        return moves;
    }
};
