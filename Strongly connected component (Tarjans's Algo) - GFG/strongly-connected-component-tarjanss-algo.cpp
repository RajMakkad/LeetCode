// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    void Tarjan(int node,int parent,vector<int> g[],vector<int> &disc,vector<int> &low,vector<int> &inStack,stack<int> &s,vector<vector<int>> &ans){
        static int time = 0;
        disc[node] = low[node] = time++;
        inStack[node] = 1;
        s.push(node);

        for(auto &i:g[node]){
            if(disc[i] == -1){
                Tarjan(i,node,g,disc,low,inStack,s,ans);
                low[node] = min(low[node],low[i]);
            }
            else if(inStack[i] == 1) low[node] = min(low[node],disc[i]);
        }

        if(disc[node] == low[node]){
            vector<int> sub;
            while(s.top() != node){
                sub.push_back(s.top());
                inStack[s.top()] = 0;
                s.pop();
            }

            sub.push_back(s.top());
            inStack[s.top()] = 0;
            s.pop();
            
            sort(sub.begin(),sub.end());
            ans.push_back(sub);
        }
    }
	public:
    vector<vector<int>> tarjans(int n, vector<int> g[]){
        vector<int> disc(n,-1), low(n,-1), inStack(n,0);
        stack<int> s;
        vector<vector<int>> ans;

        for(int i = 0;i<n;i++){
            if(disc[i] == -1){
                Tarjan(i,-1,g,disc,low,inStack,s,ans);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends