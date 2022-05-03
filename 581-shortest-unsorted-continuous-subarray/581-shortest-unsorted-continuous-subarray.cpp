class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub;
        sub = nums;
        sort(sub.begin(),sub.end());

        int s = 0;
        int e = n - 1;
        
        for(s = 0;s<n;s++){
            if(nums[s] != sub[s]) break;
        }

        for(e = n - 1;e>=s;e--){
            if(nums[e] != sub[e]) break;
        }

        return e - s + 1;
    }
};