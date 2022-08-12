class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root == p || root == q) return root;
        
        TreeNode *x = lowestCommonAncestor(root->left, p, q);
        TreeNode *y = lowestCommonAncestor(root->right, p, q);
        
        if(x and y) return root;
        else if(x) return x;
        return y;
    }
};