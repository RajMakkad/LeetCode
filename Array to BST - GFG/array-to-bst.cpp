// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    void create(int s,int e,vector<int> &nums,vector<int> &ans){
        if(s > e) return ;
        int m = s + (e - s)/2;
        ans.push_back(nums[m]);
        create(s,m - 1,nums,ans);
        create(m + 1,e,nums,ans);
    }
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        create(0,n - 1,nums,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends