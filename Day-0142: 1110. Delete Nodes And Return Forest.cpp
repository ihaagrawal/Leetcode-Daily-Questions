// 1110. Delete Nodes And Return Forest (MEDIUM)
// https://leetcode.com/problems/delete-nodes-and-return-forest/description/?envType=daily-question&envId=2024-07-17


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
    bool set[1001] = {};

    void check(TreeNode* &root, bool f, vector<TreeNode*>& result){
        if(!root) return;

        check(root->left, set[root->val], result);
        check(root->right, set[root->val], result);

        if(!set[root->val] && f) result.push_back(root);
        if(set[root->val]) root = nullptr;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        for(int n : to_delete) set[n] = true;
        check(root, true, result);
        return result;
    }
};
