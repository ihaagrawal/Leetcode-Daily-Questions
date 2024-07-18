// 1530. Number of Good Leaf Nodes Pairs (MEDIUM)
// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/?envType=daily-question&envId=2024-07-18


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

    int result = 0;
    vector<int> check(TreeNode* root, int d){
        if(!root) return {};
        if(!root->left && !root->right) return {1};

        vector<int> lefty = check(root->left, d);
        vector<int> righty = check(root->right, d);
        vector<int> temp;

        for(auto& l : lefty){
            for(auto& r : righty){
                if(l + r <= d) result++;
            }
            l++;
            if(l < d) temp.push_back(l); 
        }

        for(auto& r : righty){
            r++;
            if(r < d) temp.push_back(r);
        }

        return temp;
    }

    int countPairs(TreeNode* root, int distance) {
        check(root, distance);
        return result;
    }
};
