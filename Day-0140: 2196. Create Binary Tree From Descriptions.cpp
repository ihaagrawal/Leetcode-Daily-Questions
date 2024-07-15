// 2196. Create Binary Tree From Descriptions (MEDIUM)
// https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2024-07-15


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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;

        for (auto& arr : descriptions) {
            int parent = arr[0], child = arr[1], isLeft = arr[2];
            children.insert(child);
            if (mp.find(parent) == mp.end()) mp[parent] = new TreeNode(parent);
            if (mp.find(child) == mp.end()) mp[child] = new TreeNode(child);
            if (isLeft == 1) mp[parent]->left = mp[child];
            else mp[parent]->right = mp[child];
        }

        int root = -1;
        for (auto& arr : descriptions) {
            if (children.find(arr[0]) == children.end()) {
                root = arr[0];
                break;
            }
        }

        return mp[root];
    }
};
