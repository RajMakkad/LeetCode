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
    pair<int, int> solve(TreeNode *node, int &ans){
        if(!node)
            return {0, 0};
        auto left = solve(node->left, ans);
        auto right = solve(node->right, ans);
        ans += abs(left.first - left.second);
        ans += abs(right.first - right.second);
        return {left.first + right.first + 1, left.second + right.second + node->val};
    }
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};