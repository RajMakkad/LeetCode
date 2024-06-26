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
    void fetch(TreeNode *node, vector<TreeNode*> &nodes){
        if(!node)
            return ;
        fetch(node->left, nodes);
        nodes.push_back(node);
        fetch(node->right, nodes);
    }
    TreeNode *bst(vector<TreeNode*> &nodes, int s, int e){
        if(e < s)
            return nullptr;
        int m = s + (e - s)/2;
        nodes[m]->left = bst(nodes, s, m - 1);
        nodes[m]->right = bst(nodes, m + 1, e);
        return nodes[m];
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        fetch(root, nodes);
        return bst(nodes, 0, (int)nodes.size() - 1);
    }
};