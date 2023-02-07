//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        int maxLength(vector<int> &arr,int n){
            int ans = 0;
            int s = 0;
            int cnt = 0;
            int idx = 0;
            
            for(int i = 0;i < n;i++){
                if(arr[i] < 0) {
                    if(cnt == 0)
                        idx = i + 1;
                    cnt++;
                }
                
                if(arr[i] == 0){
                    s = i + 1;
                    cnt = 0;
                    idx = 0;
                }
                
                if(cnt % 2 == 0)
                    ans = max(ans, i - s + 1);
                else 
                    ans = max(ans, i - idx + 1);
            }
            
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends