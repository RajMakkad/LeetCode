class Solution {
    void fill(int node, int &parent, vector<int> &visited, vector<int> g[], vector<vector<int>> &ans){
        visited[node] = 1;
        for(auto &i: g[node]){
            if(!visited[i]){
                ans[i].push_back(parent);
                fill(i, parent, visited, g, ans);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        vector<vector<int>> ans(n);
        for(auto &i: edges)
            g[i[0]].push_back(i[1]);
        for(int i = 0; i < n; i++){
            vector<int> visited(n, 0);
            fill(i, i, visited, g, ans);
        }
        return ans;
    }
};