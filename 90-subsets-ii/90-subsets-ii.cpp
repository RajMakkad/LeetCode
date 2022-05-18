class Solution {
    vector<vector<int>> ans;
    void subsets(int x,vector<int> &sub,vector<int> &nums){
        ans.push_back(sub);

        for(int i = x;i<nums.size();i++){
            if(i != x and nums[i] == nums[i - 1]) continue;

            sub.push_back(nums[i]);
            subsets(i + 1,sub,nums);

            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        subsets(0,sub,nums);

        return ans;
    }
};