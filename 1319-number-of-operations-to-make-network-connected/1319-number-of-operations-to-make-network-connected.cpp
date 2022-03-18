class Solution {
    void group(int node,vector<int> g[],vector<int> &vis){
        vis[node] = 1;
        for(auto &i:g[node]){
            if(vis[i] == 0){
                group(i,g,vis);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m + 1 < n) return -1;
        
        vector<int> g[n];
        vector<int> vis(n,0);
        for(auto &i:connections){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        int ans = 0;

        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                ans++;
                group(i,g,vis);
            }
        }

        return ans - 1;
    }
};