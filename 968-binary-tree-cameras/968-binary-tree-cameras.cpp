class Solution {
    int ans = 0;
    int solve(TreeNode* node){
        if(!node) return 0; // no need
        if(!node->left and !node->right) return 1; // need
        
        int x = solve(node->left);
        int y = solve(node->right);
        
        if(x == 0 and y == 0) return 1;
        if(x == 1 || y == 1){
            ans++;
            return 2;
        }
        
        return 0; 
    }
public:
    int minCameraCover(TreeNode* root) {
        if(solve(root) == 1) ans++;
        return ans;
    }
};