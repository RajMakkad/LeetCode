class Solution {
    bool solve(TreeNode *node, long long int min_, long long int max_){
        if(!node) return true;
        long long int x = node->val;
        
        return (x > min_ and max_ > x) and solve(node->left, min_, node->val) and solve(node->right, node->val, max_);
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, -1e17, 1e17);
    }
};