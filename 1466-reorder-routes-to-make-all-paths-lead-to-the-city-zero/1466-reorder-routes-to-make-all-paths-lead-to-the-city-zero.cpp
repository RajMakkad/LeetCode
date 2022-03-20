class Solution {
public:
    
    void redirect(int node,vector<int> g[],vector<int> &vis,map<pair<int,int>,int> &mp,int &ans){
        vis[node] = 1;

        for(auto i:g[node]){
            if(vis[i] == 0){
                redirect(i,g,vis,mp,ans);
                if(mp[{i,node}]) ans++;
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> g[n],vis(n,0);
        map<pair<int,int>,int> mp;

        for(auto i:connections){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);

            mp[{i[1],i[0]}] = 1; // madeup road.
        }

        int ans = 0;
        redirect(0,g,vis,mp,ans);

        return ans;
    }
};