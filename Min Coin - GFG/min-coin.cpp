// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount){
        vector<int> dp(amount + 1,1e9);
        dp[0] = 0;
    
        for(int i = 0;i<=amount;i++){
            if(dp[i] == 1e9) continue;
            for(auto &p:nums){
                if(i + p <= amount) dp[i + p] = min(dp[i + p],dp[i] + 1);
            }
        }
    
        return dp[amount] == 1e9 ? -1 : dp[amount]; 
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends