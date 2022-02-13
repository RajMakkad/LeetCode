class Solution {
public:
    void getseq(vector<int>&nums,vector<int>&sub,vector<vector<int>>&ans,int &i){
        if(i>=nums.size()){
            ans.push_back(sub);
        }
        else{
            sub.push_back(nums[i++]);
            getseq(nums,sub,ans,i);
            sub.pop_back();
            getseq(nums,sub,ans,i);
            i--;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        int i = 0;
        getseq(nums,sub,ans,i);

        return ans;
    }
};