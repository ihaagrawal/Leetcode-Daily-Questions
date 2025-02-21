// 1261. Find Elements in a Contaminated Binary Tree (MEDIUM)
// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/?envType=daily-question&envId=2025-02-21

class FindElements {
private:
    TreeNode* root;
    unordered_set<int> values;

    void recover(TreeNode* node, int value) {
        if (!node) return;
        node->val = value;
        values.insert(value);
        recover(node->left, 2 * value + 1);
        recover(node->right, 2 * value + 2);
    }

public:
    FindElements(TreeNode* root) {
        this->root = root;
        if (root) recover(root, 0); 
    }

    bool find(int target) {
        return values.count(target) > 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
