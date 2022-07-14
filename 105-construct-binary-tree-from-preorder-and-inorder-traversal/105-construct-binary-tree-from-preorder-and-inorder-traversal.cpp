class Solution {
    unordered_map<int, int> mp;
    TreeNode *solve(int &idx, int l, int h, vector<int>& preorder, vector<int>& inorder){
        TreeNode *node = NULL;
        if(h >= l){
            idx++;
            node = new TreeNode(preorder[idx]);
            int mid = mp[preorder[idx]];
            
            if(idx + 1 < preorder.size()) node->left = solve(idx, l, mid - 1, preorder, inorder);
            
            if(idx + 1 < preorder.size()) node->right = solve(idx, mid + 1, h, preorder, inorder);
        }
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i < inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        int idx = -1;
        return solve(idx, 0, inorder.size() - 1, preorder, inorder);
    }
};