// 129. Sum Root to Leaf Numbers (MEDIUM)
// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=daily-question&envId=2024-04-15

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

    int sum(TreeNode* root, int current){
        int left, right;
        if(!root) return 0;
        current = (current*10 )+ root->val;
        if(root->left==nullptr && root->right==nullptr) return current;
        left=sum(root->left, current);
        right=sum(root->right, current);
        return left+right;
    }

    int sumNumbers(TreeNode* root) {
        int current=0;
        return sum(root, current);
    }
};
