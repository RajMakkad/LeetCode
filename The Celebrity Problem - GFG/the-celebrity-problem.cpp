// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& g, int n) {
        int celeb = -1;
        for(int r = 0;r < n;r++){
            bool pass = true;
            for(int c = 0;c < n;c++){
                if(g[r][c] == 1){
                    pass = false;
                    break;
                }
            }
            
            if(pass){
                celeb = r;
                break;
            }
        }
        
        int count = 0;
        for(int i = 0;i < n;i++){
            if(g[i][celeb] == 1) count++;
        }
        
        return count == n - 1 ? celeb : -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends