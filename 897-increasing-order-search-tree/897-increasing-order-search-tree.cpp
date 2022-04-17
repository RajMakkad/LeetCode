

class Solution {
    void solve(TreeNode* &node, TreeNode *root){
        if(!root) return ;
        
        solve(node,root->left);
        node->right = new TreeNode(root->val);
        
        node = node->right;
        solve(node,root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *node = new TreeNode(0);
        TreeNode *ans = node;
        solve(node,root);
        
        return ans->right;
    }
};