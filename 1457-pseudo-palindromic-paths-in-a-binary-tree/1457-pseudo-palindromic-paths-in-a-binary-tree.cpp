class Solution {
    int solve(TreeNode *node, int bits){
        if(!node)
            return 0;
        bits = bits ^ (1 << node->val);
        if(!node->left and !node->right)
            return ((bits & (bits - 1)) == 0);
        return solve(node->left, bits) + solve(node->right, bits);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return solve(root, 0);
    }
};