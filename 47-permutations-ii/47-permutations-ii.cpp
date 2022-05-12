class Solution {
    vector<vector<int>> ans;
    void permutations(int idx,vector<int> &nums){
        int n = nums.size();
        if(idx == n){
            ans.push_back(nums);
            return ;
        }

        set<int> swapped;

        for(int i = idx;i<n;i++){
            if(swapped.find(nums[i]) != swapped.end()) continue;
            
            swap(nums[idx],nums[i]);
            permutations(idx + 1,nums);
            swap(nums[idx],nums[i]);
            
            swapped.insert(nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums){
        int idx = 0;
        vector<int> sub;
        permutations(idx,nums);

        return ans;
    }
};