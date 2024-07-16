// 2096. Step-By-Step Directions From a Binary Tree Node to Another (MEDIUM)
// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=daily-question&envId=2024-07-16


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

    void get(TreeNode* root, int& start, int& dest, string& temp, string& s, string& t){
        if(!root) return;

        if(root->val == start) s = temp;
        if(root->val == dest) t = temp;

        temp.push_back('L');
        get(root->left, start, dest, temp, s, t);
        temp.pop_back();

        temp.push_back('R');
        get(root->right, start, dest, temp, s, t);
        temp.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s, t, temp;
        get(root, startValue, destValue, temp, s, t);

        int ind = 0;
        for(int i=0;i<s.size() && i<t.size();i++){
            if(s[i] == t[i]) ind = i+1;
            else break;
        }

        string result;
        for(int i=ind;i<s.size();i++) result.push_back('U');
        for(int i=ind;i<t.size();i++) result.push_back(t[i]);

        return result;
    }
};
