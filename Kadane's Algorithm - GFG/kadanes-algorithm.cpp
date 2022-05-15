// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    long long maxSubarraySum(int a[], int n){
        long long ans = -1e7;
        long long sum = -1e7;
        
        for(int i = 0;i<n;i++){
            sum = max(sum + a[i]*1LL,a[i]*1LL);
            ans = max(ans,sum);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends