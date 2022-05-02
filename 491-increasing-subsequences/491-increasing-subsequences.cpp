class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;
        int end = 1<<n;

        for(int i = 0;i<end;i++){
            vector<int> sub;
            bool pass = true;
            for(int p = 0;p<n;p++){
                int x = i>>p;
                if((x & 1)) sub.push_back(nums[p]);
                if(sub.size() > 1){
                    int m = sub.size();
                    if(sub[m - 2] > sub[m - 1]){
                        pass = false;
                        break;
                    }
                }
            }
            if(pass and sub.size() > 1) s.insert(sub);
        }

        for(auto i:s) ans.push_back(i);

        return ans;
    }
};