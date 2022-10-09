class Solution {
public:
    bool getsum(TreeNode* root,int &k,unordered_map<int,int> &mp){
        if(!root) return false;
        int need = k - root->val;
        if(mp[need]){
            return true;
        }
        mp[root->val] = 1;
        
        if(getsum(root->left, k, mp) || getsum(root->right, k, mp)) return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        return getsum(root,k,mp);
    }
};