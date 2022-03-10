// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int height(int node,vector<int> g[]){
        int cnt = 1;
        for(auto &i:g[node]){
            cnt = max(cnt,height(i,g) + 1);
        }

        return cnt;
    }
public:
    int findHeight(int n, int a[]){
        vector<int> g[n];
        int node = 0;

        for(int i = 0;i<n;i++){
            if(a[i] == -1) node = i;
            else g[a[i]].push_back(i);
        }

        return height(node,g);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends