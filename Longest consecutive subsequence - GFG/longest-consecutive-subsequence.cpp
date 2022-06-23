// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N){
        vector<int> dp(100001, 0);
        for(int i = 0;i < N;i++){
            dp[arr[i]] = 1;
        }
        
        int ans = 1;
        for(int i = 1;i <= 100000;i++){
            if(dp[i] > 0) dp[i] += dp[i - 1];
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends