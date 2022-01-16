class Solution {
public:
    int wiggleMaxLength(vector<int>& nums){
        int n = nums.size();
        int ans = 0;
        vector<int> v;
        v.push_back(nums[0]);

        for(int i = 1;i<n;i++){  // small start
            if(v.size()%2){
                if(nums[i] > v.back()) v.push_back(nums[i]);
                else if(nums[i] < v.back()) v.back() = nums[i];
            }
            else{
                if(nums[i] > v.back()) v.back() = nums[i]; 
                else if(nums[i] < v.back()) v.push_back(nums[i]);
            }
        }

        ans = max(ans,(int)v.size());
        v.clear();
        v.push_back(nums[0]);

        for(int i = 1;i<n;i++){  // big start
            if(v.size()%2){
                if(nums[i] > v.back()) v.back() = nums[i];
                else if(nums[i] < v.back()) v.push_back(nums[i]);
            }
            else{
                if(nums[i] > v.back()) v.push_back(nums[i]);
                else if(nums[i] < v.back()) v.back() = nums[i]; 
            }
        }

        ans = max(ans,(int)v.size());
        return ans;
    }
};