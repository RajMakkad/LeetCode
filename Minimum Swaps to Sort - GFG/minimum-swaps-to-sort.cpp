// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
    public:
	int minSwaps(vector<int>&nums){
        int n = nums.size();
        int ans = 0;
	    unordered_map<int,int> in;

        for(int i = 0;i<n;i++){
            in[nums[i]] = i;
        }

        sort(nums.begin(),nums.end());

        for(int i = 0;i<n;i++){
            while(in[nums[i]] != i){
                ans++;
                swap(nums[i],nums[in[nums[i]]]);
            }
        }

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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends