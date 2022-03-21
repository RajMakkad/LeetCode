class Solution{
    bool isBipartite(int node,int c,vector<int> &colors,vector<int> g[]){
        colors[node] = c;
        for(auto &i:g[node]){
            if(colors[i] == -1){
                if(!isBipartite(i,(c^1),colors,g)) return false;
            }
            else if(colors[i] != (c ^ 1)) return false;
        }

        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes){
        vector<int> g[n + 1];
        for(auto &i:dislikes){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        vector<int> colors(n + 1,-1);

        for(int i = 1;i<=n;i++){
            if(colors[i] == -1){
                if(!isBipartite(i,0,colors,g)) return false;
            }
        }

        return true;
    }
};