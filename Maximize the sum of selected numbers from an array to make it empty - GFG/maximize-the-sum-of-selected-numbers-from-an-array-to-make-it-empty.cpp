//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) {
        int ans = 0;
        vector<int> v(1e5 + 1, 0);
        
        for(int i = 0;i < n;i++){
            v[a[i]]++;
        }
        
        for(int i = 1e5;i >= 1;i--){
            ans += v[i] * i;
            v[i - 1] = max(v[i - 1] - v[i], 0);
        }
        
        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends