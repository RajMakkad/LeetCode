// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    vector<vector<int>> findDistance(vector<vector<char>>& matrix, int n, int m){
        vector<vector<int>> ans(n,vector<int>(m));
        queue<pair<int,int>> q;
    
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(matrix[r][c] == 'O') ans[r][c] = 1e9;
                else if(matrix[r][c] == 'B'){
                    ans[r][c] = 0;
                    q.push({r,c});
                }
                else ans[r][c] = -1;
            }
        }
    
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
    
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
    
            for(int i = 0;i<4;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];
    
                if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < m and matrix[x1][y1] != 'W' and ans[x1][y1] > ans[x][y] + 1){
                    ans[x1][y1] = ans[x][y] + 1;
                    q.push({x1,y1});
                }
            }
        }
    
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(ans[r][c] == 1e9) ans[r][c] = -1;
            }
        }
    
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
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends