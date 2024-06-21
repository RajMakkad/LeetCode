class Solution {
    unordered_map<int, int> l, r, ans;
    int height(TreeNode *node){
        if(!node)
            return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        l[node->val] = lh;
        r[node->val] = rh;
        return max(lh, rh) + 1;
    }
    void solve(TreeNode *node, int max_, int depth){
        if(!node)
            return ;
        ans[node->val] = max_;
        solve(node->left, max(max_, r[node->val] + depth), depth + 1);
        solve(node->right, max(max_, l[node->val] + depth), depth + 1);
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        solve(root, 0, 0);
        vector<int> submit;
        for(auto &i: queries)
            submit.push_back(ans[i]);
        return submit;
    }
};