//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    void solve(int n, int x, vector<int> &sub, vector<vector<int>> &ans){
        if(n == 0){
            ans.push_back(sub);
            return;
        }
        
        if(x <= n) {
            sub.push_back(x);
            solve(n - x, x, sub, ans);
            sub.pop_back();
        }
        
        if(x > 1) solve(n, x - 1, sub, ans);
    }
	public:
    vector<vector<int>> UniquePartitions(int n) {
        vector<int> sb;
        vector<vector<int>> ans;
        
        solve(n, n, sb, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends