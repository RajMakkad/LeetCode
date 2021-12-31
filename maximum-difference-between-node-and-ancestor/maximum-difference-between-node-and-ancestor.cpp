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
    pair<int,int> get(TreeNode *root,int &ans){
        if(!root->left and !root->right) return {root->val,root->val};
        int mx = 0;
        int mn = 1e9;
        if(root->left){
            auto u = get(root->left,ans);
            ans = max({ans,abs(u.first - root->val),abs(u.second - root->val)});
            mx = max(root->val,u.first);
            mn = min(root->val,u.second);
        }
        
        if(root->right){
            auto u = get(root->right,ans);
            ans = max({ans,abs(u.first - root->val),abs(u.second - root->val)});
            mx = max({mx,root->val,u.first});
            mn = min({mn,root->val,u.second});
        }
        
        return {mx,mn};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        get(root,ans);
        return ans;
    }
};