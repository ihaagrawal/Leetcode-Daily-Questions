// 1382. Balance a Binary Search Tree (MEDIUM)
// https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2024-06-26

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

    void inorder(TreeNode* root, vector<int>& arr){
        vector<TreeNode*> st;
        TreeNode* node = root;

        while(node || !st.empty()){
            while(node){
                st.push_back(node);
                node = node->left;
            }
            node = st.back();
            st.pop_back();
            
            arr.push_back(node->val);
            node = node->right;
        }
    }

    TreeNode* balanced(vector<int>& arr, int l, int r){
        if(l>r) return NULL;
        int m = (l+r)/2;
        TreeNode* left = (l>m-1) ? NULL : balanced(arr, l, m-1);
        TreeNode* right = (m+1>r) ? NULL : balanced(arr, m+1, r);
        return new TreeNode(arr[m], left, right); 
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return balanced(arr, 0, arr.size()-1);
    }
};
