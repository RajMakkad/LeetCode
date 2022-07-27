class Solution {
    
public:
    void flatten(TreeNode* node) {
        if(!node) return ;
        
        flatten(node->left);
        flatten(node->right);
        
        TreeNode *next = node->right;
        
        node->right = node->left;
        node->left = NULL;
        
        TreeNode *p = node;
        while(p->right) p = p->right;
        
        p->right = next;
    }
};