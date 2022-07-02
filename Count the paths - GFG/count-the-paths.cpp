// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int ans = 0;
    void dfs(int node, int d, vector<int> &vis, vector<int> g[]){
        vis[node] = 1;
        
        if(node == d) ans++;
        
        for(auto i:g[node]){
            if(vis[i] == 0){
                dfs(i, d, vis, g);
            }
        }
        
        vis[node] = 0;
    }
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<int> g[n];
	    for(auto i:edges){
	        g[i[0]].push_back(i[1]);
	    }
	    
	    vector<int> vis(n, 0);
	    
	    dfs(s, d, vis, g);
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends