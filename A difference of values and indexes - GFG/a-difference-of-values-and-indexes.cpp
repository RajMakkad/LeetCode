//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n){ 
        int ans = 0;
        int a = arr[n - 1] + n;
        int b = n - arr[n - 1];
        
        for(int i = n - 2;i >= 0;i--){
            ans = max({ans, a - arr[i] - i - 1, b + arr[i] - i - 1});
            a = max(a, arr[i] + i + 1);
            b = max(b, i + 1 - arr[i]);
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends