class Solution {
    unordered_map<int,vector<int>> mp;
    void dfs(int node,int color,string &s,vector<int> &vis,vector<int> g[]){
        vis[node] = color;
        mp[color].push_back(s[node] - 'a');

        for(auto i:g[node]){
            if(vis[i] == 0) 
                dfs(i,color,s,vis,g);
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& p){
        int n = s.size();
        vector<int> vis(n,0), g[n];

        for(auto i:p){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        for(int i = 0;i<n;i++){
            if(vis[i] == 0)
                dfs(i,i + 1,s,vis,g);
        }

        for(auto &i:mp) sort(i.second.begin(),i.second.end());
        for(int i = n - 1;i>=0;i--){
            s[i] = mp[vis[i]].back() + 'a';
            mp[vis[i]].pop_back();
        }

        return s;
    }
};
