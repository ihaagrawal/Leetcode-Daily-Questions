// 988. Smallest String Starting From Leaf (MEDIUM)
// https://leetcode.com/problems/smallest-string-starting-from-leaf/description/?envType=daily-question&envId=2024-04-17

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
    string result="";
    void smallest(TreeNode* root, string current){
        if(!root) return;
        
        current = char(root->val + 'a') + current;

        if(!root->left && !root->right){
            if(result=="" || result>current)
                result=current;
            return;
        }

        smallest(root->left, current);
        smallest(root->right, current);
        
    }

    string smallestFromLeaf(TreeNode* root) {
        smallest(root, "");
        return result;
    }
};
