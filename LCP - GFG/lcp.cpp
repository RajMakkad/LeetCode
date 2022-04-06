// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string a[], int n){
        string ans = a[0];

        for(int i = 1;i<n;i++){
            int len = min(a[i].length(),ans.length());
            int j = 0;
            for(j = 0;j<len;j++){
                if(a[i][j] != ans[j]) break;
            }

            ans = ans.substr(0,j);
        }

        if(ans.empty()) ans = "-1";
        return ans;
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
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends