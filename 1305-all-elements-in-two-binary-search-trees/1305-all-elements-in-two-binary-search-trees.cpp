
class Solution {
    void getElements(TreeNode *root,vector<int> &v){
        if(!root) return ;
        
        getElements(root->left,v);
        v.push_back(root->val);
        getElements(root->right,v);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
        vector<int> v;
        getElements(root1,v);
        getElements(root2,v);
        
        sort(v.begin(),v.end());
        
        return v;
    }
};