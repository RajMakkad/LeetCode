const int N = 2e5 + 10;

class Solution {
    int reach[N];
    void dfs(int node, vector<int> g[]){
        reach[node] = 1;
        for(auto i:g[node]){
            if(reach[i] == 0) 
                dfs(i, g);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> g[n];
        for(auto i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        
        memset(reach, 0, sizeof(reach));
        reach[source] = 1;
        
        dfs(source, g);
        
        return reach[destination];
    }
};