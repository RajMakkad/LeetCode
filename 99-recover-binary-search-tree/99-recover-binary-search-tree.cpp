class Solution {
    TreeNode *s_1 = NULL, *s_2 = NULL, *pre = NULL; 
    void inorder(TreeNode *node){
        if(!node) return ;
        inorder(node->left);
        
        if(pre and pre->val > node->val){
            if(!s_1){
                s_1 = pre;
                s_2 = node;
            }
            else s_2 = node;
        }
        
        pre = node;
        inorder(node->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode *node = root;
        s_1 = s_2 = pre = NULL;
        inorder(node);
        
        swap(s_1->val,s_2->val);
    }
};