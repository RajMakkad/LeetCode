class Solution {
public:
    void getcps(int node,int parent,vector<int> adj[],vector<int> &dis,vector<int> &low,vector<vector<int>> &ans){
        static int time = 0;
        dis[node] = low[node] = time++;

        for(auto i: adj[node]){
            if(i == parent) continue;
            if(dis[i] == -1){
                getcps(i,node,adj,dis,low,ans);
                low[node] = min(low[node],low[i]);
                if(low[i] > dis[node]) ans.push_back({i,node});
            }
            else{
                low[node] = min(low[node],low[i]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> dis(n,-1),low(n,-1);

        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<vector<int>> ans;
        getcps(0,-1,adj,dis,low,ans);

        return ans;
    }
};