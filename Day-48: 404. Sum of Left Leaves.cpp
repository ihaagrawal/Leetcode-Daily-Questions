// 404. Sum of Left Leaves (EASY)
// https://leetcode.com/problems/sum-of-left-leaves/description/?envType=daily-question&envId=2024-04-14

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;

        int sum=0;
        if(root->left){
            if(!root->left->left && !root->left->right) sum +=root->left->val;
            else sum += sumOfLeftLeaves(root->left);
        }

        sum+=sumOfLeftLeaves(root->right);
        return sum;
    }
};
