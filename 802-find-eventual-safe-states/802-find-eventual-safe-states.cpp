class Solution{
    void isCycle(int node,vector<int> &vis,vector<vector<int>>& g){
        vis[node] = 2; // visited + inStack

        for(auto &i:g[node]){
            if(vis[i] == 0) isCycle(i,vis,g);
            if(vis[i] == 2) return ;
        }

        vis[node] = 1; // visited
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g){
        int n = g.size();
        vector<int> vis(n,0),safe;

        for(int i = 0;i<n;i++){
            if(vis[i] == 0) isCycle(i,vis,g);
            if(vis[i] == 1) safe.push_back(i);
        }

        return safe;
    }
};