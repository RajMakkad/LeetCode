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
    int sum = 0;
public:
    TreeNode* bstToGst(TreeNode* node) {
        if(!node) return NULL;
        
        bstToGst(node->right);
        sum += node->val;
        node->val = sum;
        
        bstToGst(node->left);
        
        return node;
    }
};