// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
bool findbridge(int node,int parent,vector<int> g[],vector<int> &disc, vector<int> &low, int c, int d){
    static int time = 0;
    disc[node] = low[node] = time++;

    for(auto &i:g[node]){
        if(i == parent) continue;
        if(disc[i] == -1){
            if(findbridge(i,node,g,disc,low,c,d)) return true;
            low[node] = min(low[node],low[i]);
        }
        else low[node] = min(low[node],disc[i]);
        if(low[i] > disc[node]){
            if((i == c and node == d) || (i == d and node == c)) return true;
        }
    }

    return false;
}
public:
    
    int isBridge(int n, vector<int> g[], int c, int d){
        vector<int> disc(n,-1), low(n,-1);
        for(int i = 0;i<n;i++){
            if(disc[i] == -1){
                if(findbridge(i,-1,g,disc,low,c,d)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends