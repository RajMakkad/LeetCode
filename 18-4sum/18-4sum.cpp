class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(),nums.end());

        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                int sum = target - (nums[i] + nums[j]);
                int s = j + 1;
                int e = n - 1;

                while(e > s){
                    if(nums[s] + nums[e] > sum) e--;
                    else if(nums[s] + nums[e] < sum) s++;
                    else
                    {
                        vector<int> v = {nums[i],nums[j],nums[s++],nums[e]};
                        while(s < n and nums[s] == nums[s - 1]) s++;
                        st.insert(v);
                    }
                }
                while(j + 1< n and nums[j + 1] == nums[j]) j++;
            }
            while(i + 1 < n and nums[i + 1] == nums[i]) i++;
        }

        vector<vector<int>> ans = {st.begin(),st.end()};

        return ans;
    }
};