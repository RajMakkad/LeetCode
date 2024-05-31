class Solution {
    int getPsuedoPaths(TreeNode *node, vector<int> bits){
        if(!node)
            return 0;
        bits[node->val]++;
        if(!node->left and !node->right){
            int odd = 0;
            for(int i = 0;i <= 9; i++)
                odd += (bits[i] & 1) ? 1 : 0;
            bits[node->val]--;
            return odd <= 1;
        }
        int ans = getPsuedoPaths(node->left, bits) + getPsuedoPaths(node->right, bits);
        bits[node->val]--;
        return ans;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> bits(9 + 1, 0);
        return getPsuedoPaths(root, bits);
    }
};