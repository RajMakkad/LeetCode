class Solution {
    void solve(TreeNode *node, int idx, vector<int> &v){
        if(!node) return ;
        
        if(idx == (int)v.size()) v.push_back(node->val);
        
        solve(node->right, idx + 1, v);
        solve(node->left, idx + 1, v);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        solve(root, 0, v);
        
        return v;
    }
};