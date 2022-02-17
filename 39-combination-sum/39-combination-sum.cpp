class Solution {
    vector<vector<int>> ans;
    void get(int &i,vector<int> &candidates,vector<int> &sub,int &target){
        if(i>=candidates.size() || target<=0){
            if(!target) ans.push_back(sub);
            return ;
        }

        target -= candidates[i];
        sub.push_back(candidates[i]);
        get(i,candidates,sub,target);
        target += candidates[i];
        sub.pop_back();
        
        i++;
        get(i,candidates,sub,target);
        i--;
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i = 0;
        vector<int> sub;

        get(i,candidates,sub,target);

        return ans;
    }
};
