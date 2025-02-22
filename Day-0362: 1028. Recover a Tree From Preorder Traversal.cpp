// 1028. Recover a Tree From Preorder Traversal (HARD)
// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/?envType=daily-question&envId=2025-02-22

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

    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root = nullptr;
        vector<pair<TreeNode*, int>> vec;

        int n = traversal.size();
        int depth = 0;

        for(int i=0;i<n;i++){
            int it = 0;
            while(isdigit(traversal[i])){
                it = 10 * it + traversal[i] - '0';
                i++;
            }

            TreeNode* newnode = new TreeNode(it);
            if(depth == 0) root = newnode;
            else{
                while(vec.back().second != depth - 1) vec.pop_back();
                if(vec.back().first -> left == nullptr) vec.back().first -> left = newnode;
                else vec.back().first -> right = newnode;
            }

            vec.emplace_back(newnode, depth);
            depth = 0;
            while(traversal[i] == '-') depth++, i++;
            i--;
        }

        return root;
    }
};
