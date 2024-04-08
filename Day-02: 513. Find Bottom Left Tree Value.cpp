// 513. Find Bottom Left Tree Value (MEDIUM)
// https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=daily-question&envId=2024-02-28

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int left;

        while(!q.empty())
            {
                TreeNode* temp=q.front();
                q.pop();
                left=temp->val;
                if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);

            }
        return left;
    }
};
