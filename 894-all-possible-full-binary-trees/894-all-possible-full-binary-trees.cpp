class Solution {
    map<int,vector<TreeNode*>> dp;
    
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n == 1){
            TreeNode* node = new TreeNode(0);
            return {node};
        }
        
        if(dp.find(n) != dp.end()) return dp[n];
        
        for(int i = 1;i < n - 1;i += 2){
            vector<TreeNode*> l = allPossibleFBT(i);
            vector<TreeNode*> r = allPossibleFBT(n - i - 1);
            
            for(auto x:l){
                for(auto y:r){
                    TreeNode* node = new TreeNode(0);
                    node->left = x;
                    node->right = y;
                    dp[n].push_back(node);
                }
            }
        }
        return dp[n];
    }
};