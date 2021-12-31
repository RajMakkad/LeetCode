/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root,int cmax = 0,int cmin = 1e9) {
        if(!root) return cmax - cmin;
        cmax = max(cmax,root->val);
        cmin = min(cmin,root->val);
        
        return max(maxAncestorDiff(root->left,cmax,cmin),maxAncestorDiff(root->right,cmax,cmin));
    }
};