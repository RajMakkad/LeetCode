class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL;
        if(original->val == target->val) return cloned;
        
        TreeNode *x = getTargetCopy(original->left,cloned->left,target);
        TreeNode *y = getTargetCopy(original->right,cloned->right,target);
        
        if(x) return x;
        else return y;
    }
};