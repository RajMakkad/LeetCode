class Solution {
    void getsum(TreeNode *root,int &num,int &ans){
        if(!root) return ;
        if(!root->left and !root->right){
            ans += (num<<1) + root->val;
            return ;
        }
        
        num = num<<1;
        num += root->val;
        getsum(root->left,num,ans);
        getsum(root->right,num,ans);
        num /= 2;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        int num = 0;
        
        getsum(root,num,ans);
        return ans;
    }
};