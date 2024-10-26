// 2458. Height of Binary Tree After Subtree Removal Queries (HARD)
// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/?envType=daily-question&envId=2024-10-26


const int N = 100001;

class Solution {
public:
    int hgt[N], maxHgt[N];

    int getHeight(TreeNode* root) {
        if (!root) return -1;
        int v = root->val;
        if (hgt[v] != -1) return hgt[v];
        return hgt[v] = 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void dfs(TreeNode* root, int lvl, int maxLvl) {
        if (!root) return;
        int v = root->val;
        maxHgt[v] = maxLvl;
        dfs(root->left, lvl + 1, max(maxLvl, 1 + lvl + getHeight(root->right)));
        dfs(root->right, lvl + 1, max(maxLvl, 1 + lvl + getHeight(root->left)));
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        memset(hgt, -1, sizeof(hgt));
        memset(maxHgt, -1, sizeof(maxHgt));
        getHeight(root);
        dfs(root, 0, 0);

        vector<int> ans(queries.size());
        int i = 0;
        for (int q : queries) {
            ans[i++] = maxHgt[q];
        }
        return ans;
    }
};
