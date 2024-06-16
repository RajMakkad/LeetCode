class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long ans = 0, mover = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(mover >= n)
                break;
            while(mover + 1 < nums[i] and mover < n){
                mover += mover + 1;
                ans++;
            }
            mover += nums[i];
        }
        while(mover < n){
            mover += mover + 1;
            ans++;
        }
        return ans;
    }
};