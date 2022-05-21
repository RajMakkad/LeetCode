class Solution {
    int ans = 0;
    vector<int> avgNode(TreeNode *node){
        if(!node) return {0,0};
        
        auto l = avgNode(node->left);
        auto r = avgNode(node->right);
        
        int sum = l[0] + node->val + r[0];
        int count = l[1] + 1 + r[1];
        
        if(sum/count == node->val) ans++;
        return {sum,count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        avgNode(root);
        return ans;
    }
};