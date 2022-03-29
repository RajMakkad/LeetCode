class Solution{
    vector<int> vis, disc, low;
    void runwild(int node,int parent,vector<int> g[],vector<vector<int>>& connections,vector<vector<int>>& ans){
        vis[node] = 1;
        static int time = 0;
        disc[node] = low[node] = time++;

        for(auto &i:g[node]){
            if(i == parent) continue;
            if(vis[i] == 0){
                runwild(i,node,g,connections,ans);
                low[node] = min(low[node],low[i]);
            }
            else low[node] = min(low[node],disc[i]);

            if(low[i] > disc[node]){
                ans.push_back({node,i});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> g[n];
        vis.resize(n);
        disc.resize(n);
        low.resize(n);
        vector<vector<int>> ans;

        for(auto &i:connections){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        runwild(0,-1,g,connections,ans);
        return ans;
    }
};