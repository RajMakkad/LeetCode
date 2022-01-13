class Solution {
	bool is_arithmatic(int l,int r,vector<int> nums){
		sort(nums.begin() + l,nums.begin() + r + 1);
		int d = nums[l + 1] - nums[l];

		for(int i = l + 1;i<=r;i++){
			if(nums[i] - nums[i - 1] != d) return false;
		}

		return true;
	}
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r){
		int n = l.size();
		vector<bool> ans(n,false);

		for(int i = 0;i<n;i++){
			if(r[i] != l[i] and is_arithmatic(l[i],r[i],nums)) ans[i] = true;
		}
        
        return ans;
    }
};