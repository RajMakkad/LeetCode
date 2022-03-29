// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:

    void getcomponents(int node,vector<int> adj[],vector<int> &dis,vector<int> &low,vector<int> &instack,stack<int> &st,vector<vector<int>> &ans){
        static int time = 0;
        dis[node] = low[node] = time++;
        st.push(node);
        instack[node] = 1;

        for(auto v: adj[node]){
            if(dis[v] == -1){
                getcomponents(v,adj,dis,low,instack,st,ans);
                low[node] = min(low[node],low[v]);
            }
            else if(instack[v] == 1){
                low[node] = min(low[node],low[v]);
            }
        }

        if(low[node] == dis[node]){
            vector<int> sub;
            while(!st.empty()){
                int u = st.top();
                st.pop();
                instack[u] = 0;
                sub.push_back(u);
                if(u == node) break;
            }
            
            sort(sub.begin(),sub.end());

            ans.push_back(sub);
        }
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<int> dis(V,-1),low(V,-1),instack(V,0);
        vector<vector<int>> ans;
        stack<int> st;

        for(int i = 0;i<V;i++){
            if(dis[i] == -1){
                getcomponents(i,adj,dis,low,instack,st,ans);
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