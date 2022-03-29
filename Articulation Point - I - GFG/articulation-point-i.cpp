// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    void disconnect(int node,int parent,vector<int> g[],vector<int> &disc,vector<int> &low,vector<int> &isArticulation){
        static int time = 0;
        disc[node] = low[node] = time++;

        int child = 0;
        for(auto &i:g[node]){
            if(i == parent) continue;
            if(disc[i] == -1){
                child++;
                disconnect(i,node,g,disc,low,isArticulation);
                low[node] = min(low[node],low[i]);

                if(low[i] >= disc[node] and parent != -1) isArticulation[node] = 1;
            }
            else low[node] = min(low[node],disc[i]);
        }

        if(child > 1 and parent == -1) isArticulation[node] = 1;
    }
  public:
    vector<int> articulationPoints(int n, vector<int> g[]){
        vector<int> disc(n,-1), low(n,-1), isArticulation(n,0);

        disconnect(0,-1,g,disc,low,isArticulation);

        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(isArticulation[i] == 1) ans.push_back(i);
        }

        if(ans.empty()) return {-1};
        return ans;
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends