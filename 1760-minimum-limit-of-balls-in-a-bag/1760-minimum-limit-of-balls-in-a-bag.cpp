class Solution {
    bool maxP(vector<int> &nums, int p, int op){
        for(auto num:nums) op = op - (num + p - 1)/p + 1;
        
        return op >= 0;
    }
public:
    int minimumSize(vector<int>& nums, int op) {
        int s = 1;
        int e = 1e9;
        int m = s + (e - s)/2;
        
        while(e >= s){
            m = s + (e - s)/2;
            if(maxP(nums, m, op)) e = m - 1;
            else s = m + 1;
        }
        
        return s;
    }
};