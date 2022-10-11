class Solution {
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    void solve(int row, int col, TreeNode *node, map<int, vector<pair<int, int>>> &mp){
        if(!node) return ;
        mp[col].push_back({row, node->val});
        
        solve(row + 1, col - 1, node->left, mp);
        solve(row + 1, col + 1, node->right, mp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        vector<vector<int>> ans;
        
        solve(0, 0, root, mp);
        
        for(auto &v:mp){
            sort(v.second.begin(), v.second.end(), comp);
            vector<int> sub;
            for(auto i:v.second) {
                sub.push_back(i.second);
            }
            
            ans.push_back(sub);
        }
        
        return ans;
    }
};