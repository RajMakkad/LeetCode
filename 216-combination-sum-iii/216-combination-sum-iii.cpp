class Solution {
    void create(int x,int n,int sum,vector<int> &sub,vector<vector<int>> &ans,vector<int> &nums){
        if(n == 0){
            if(sum == 0) ans.push_back(sub);
            return ;
        }
        
        if(x > 8) return ;

        if(sum >= nums[x]){
            sub.push_back(nums[x]);
            sum -= nums[x];
            x++;
            create(x,n - 1,sum,sub,ans,nums);
            sub.pop_back();
            x--;
            sum += nums[x];

            x++;
            create(x,n,sum,sub,ans,nums);
        }
    }
public:
    vector<vector<int>> combinationSum3(int n, int k) {
        vector<int> nums, sub;
        for(int i = 1;i<=9;i++) nums.push_back(i);

        vector<vector<int>> ans;
        create(0,n,k,sub,ans,nums);

        return ans;
    }
};