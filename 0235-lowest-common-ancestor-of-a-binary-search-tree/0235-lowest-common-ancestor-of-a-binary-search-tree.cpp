/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
pair<TreeNode*, int> lca(TreeNode *node, int x, int y){
    if(!node)
        return {NULL, 0};
    if(node->val == x || node->val == y)
        return {node, 0};
    pair<TreeNode*, int> l, r;
    l = lca(node->left, x, y);
    r = lca(node->right, x, y);

    if(l.first and r.first)
        return {node, 1};
    else if(l.first)
        return {l.first, l.second + 1};
    else if(r.first)
        return {r.first, r.second + 1};
    return {NULL, 0};
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto ans = lca(root, p->val, q->val);
        return ans.first;
    }
};