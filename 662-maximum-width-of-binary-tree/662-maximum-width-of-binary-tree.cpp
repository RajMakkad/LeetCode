class Solution {
public:
    int widthOfBinaryTree(TreeNode* node){
        long long ans = 0;
        queue<pair<TreeNode*,long long>> q;
        if(node) q.push({node,0});
        
        while(!q.empty()){
            long long s = q.front().second;
            long long e = q.back().second;
            ans = max(ans,e - s + 1);
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                
                if(node.first->left){
                    q.push({node.first->left,2*(node.second - s) + 1});
                }
                if(node.first->right){
                    q.push({node.first->right,2*(node.second - s) + 2});
                }
            }
        }
        
        return ans;
    }
};