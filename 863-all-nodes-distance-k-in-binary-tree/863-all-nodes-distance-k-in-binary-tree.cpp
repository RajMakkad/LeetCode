/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    map<TreeNode*, string> v;
    
    void solve(TreeNode* node, string &sub, TreeNode* target){
        if(!node) return ;
        v[node] = sub;
        
        sub += 'L';
        solve(node->left, sub, target);
        
        sub.pop_back();
        sub += 'R';
        solve(node->right, sub, target);
        
        sub.pop_back();
    }
    
    int res(string &a, string &b){
        int x = 0, y = 0;
        while(x < a.length() and y < b.length()){
            if(a[x] == b[y]) x++, y++;
            else break;
        }
        
        return ((a.length() - x) + (b.length() - y));
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        string sub = "";
        solve(root, sub, target);
        
        vector<int> ans;
        for(auto &i:v){
            if(res(v[target], i.second) == k) ans.push_back(i.first->val);
        }
        
        return ans;
    }
};