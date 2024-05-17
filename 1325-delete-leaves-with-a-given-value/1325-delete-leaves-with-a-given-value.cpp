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
    bool isLeaf(TreeNode *node){
        if(!node)
            return false;
        if(node->left || node->right)
            return false;
        return true;
    }
    
    void helper(TreeNode *node, int target){
        if(!node)
            return ;
        
        helper(node->left, target);
        helper(node->right, target);
        
        if(isLeaf(node->left) and node->left->val == target){
            delete node->left;
            node->left = NULL;
        }
        if(isLeaf(node->right) and node->right->val == target){
            delete node->right;
            node->right = NULL;
        }
    }
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target) {
        helper(root, target);
        if(isLeaf(root) and root->val == target)
            root = NULL;
        return root;
    }
};