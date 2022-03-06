// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int n, int m, vector<vector<int>> v)
    {
        for(int i=n-1;i>0;i--)
        {
            for(int j=m-1;j>0;j--)
            {
              v[i][j]=v[i][j]-v[i-1][j]-v[i][j-1]+v[i-1][j-1];
            }
        }
        for(int i=n-1;i>0;i--)
        {
            v[i][0]=v[i][0]-v[i-1][0];
        }
        for(int i=m-1;i>0;i--)
        {
            v[0][i]=v[0][i]-v[0][i-1];
        }
        return v;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M; 
        vector<vector<int>> after(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>after[i][j];
            }
        } 
        Solution obj;
        vector<vector<int>> before=obj.computeBeforeMatrix(N,M,after); 
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                cout<<before[i][j]<<' ';
            } 
            cout<<endl;
        }
    }
}  // } Driver Code Ends