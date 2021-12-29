class Solution {
    
    int lower_bound(vector<int>& nums, int &target){
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        
        while(r>=l){
            mid = l + (r - l)/2;
            if(nums[mid]>=target) r = mid - 1;
            else l = mid + 1;
        }
        
        if(l<nums.size() and nums[l]==target) return l;
        else return -1;
    }
    
    int upper_bound(vector<int>& nums, int &target){
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        
        while(r>=l){
            mid = l + (r - l)/2;
            if(nums[mid]<=target) l = mid + 1;
            else r = mid - 1;
        }
        
        if(r>=0 and nums[r]==target) return r;
        else return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums,target);
        int last = upper_bound(nums,target);
        
        return {first,last};
    }
};