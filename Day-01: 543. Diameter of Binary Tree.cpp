// 543. Diameter of Binary Tree (EASY)
// https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-27

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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        height(root, dia);
        return dia;
    }
    
    int height(struct TreeNode* temp, int& dia)
        {
            if(temp==NULL) return 0;
            int left=height(temp->left, dia);
            int right=height(temp->right, dia);
            dia=max(dia, left+right);
            return max(left,right)+1;
        }
};
