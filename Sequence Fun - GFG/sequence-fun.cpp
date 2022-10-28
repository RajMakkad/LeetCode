//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#define mod 1000000007
#define ll long long int
class Solution {
	public:
		int NthTerm(int n){
		    
		    ll cur = 2;
		    for(int i = 2;i <= n;i++){
		        cur = (cur * i + 1) % mod;
		    }
		    
		    return cur;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends