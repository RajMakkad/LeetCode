
class Solution {
public:
    int sumRootToLeaf(TreeNode* root,int num = 0) {
        if(!root) return 0;
        num = num*2 + root->val;
        return root->left == root->right ? num : sumRootToLeaf(root->left,num) + sumRootToLeaf(root->right,num);
    }
};