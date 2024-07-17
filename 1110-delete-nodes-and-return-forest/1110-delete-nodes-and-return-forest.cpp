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
    TreeNode *solve(TreeNode *node, vector<int> &del, vector<TreeNode*> &res){
        if(!node)
            return nullptr;
        node->left = solve(node->left, del, res);
        node->right = solve(node->right, del, res);
        if(del[node->val] == 1){
            if(node->left)
                res.push_back(node->left);
            if(node->right)
                res.push_back(node->right);
            delete node;
            node = nullptr;
        }
        return node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<int> del(1000 + 1, 0);
        for(auto &i: to_delete)
            del[i] = 1;
        vector<TreeNode*> res;
        root = solve(root, del, res);
        if(root and del[root->val] == 0)
            res.push_back(root);
        return res;
    }
};