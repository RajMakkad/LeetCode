
class Solution {
    void getElements(TreeNode *root,vector<int> &v){
        if(!root) return ;
        
        getElements(root->left,v);
        v.push_back(root->val);
        getElements(root->right,v);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
        vector<int> v1,v2,ans;
        getElements(root1,v1);
        getElements(root2,v2);
        
        int a = 0;
        int b = 0;
        
        while(a < v1.size() || b < v2.size()){
            if(a < v1.size() and b < v2.size()){
                if(v1[a] > v2[b]) ans.push_back(v2[b++]);
                else ans.push_back(v1[a++]);
            }
            else if(a < v1.size()) ans.push_back(v1[a++]);
            else ans.push_back(v2[b++]);
        }
        
        return ans;
    }
};