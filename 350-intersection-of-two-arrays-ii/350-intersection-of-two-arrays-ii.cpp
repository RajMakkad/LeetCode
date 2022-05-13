class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int x = 0, y = 0;
        
        vector<int> ans;
        while(x < nums1.size() and y < nums2.size()){
            if(nums1[x] > nums2[y]) y++;
            else if(nums1[x] < nums2[y]) x++;
            else {
                ans.push_back(nums1[x]);
                x++, y++;
            }
        }
        
        return ans;
    }
};