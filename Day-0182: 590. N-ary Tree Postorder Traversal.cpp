// 590. N-ary Tree Postorder Traversal (EASY)
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector <int> result;
    vector<int> postorder(Node* root) {
        if(!root) return result;
        for(auto& child : root->children) postorder(child);
        result.push_back(root->val);
        return result;
    }
};
