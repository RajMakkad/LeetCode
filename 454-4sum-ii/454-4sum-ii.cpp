class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int m = nums2.size();
        int p = nums3.size();
        int q = nums4.size();
        int sum = 0;
        int ans = 0;
        
        map<int,int> mp;
        
        for(int i = 0;i<p;i++){
            for(int j = 0;j<q;j++){
                sum = nums3[i] + nums4[j];
                mp[sum]++;
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                sum = nums1[i] + nums2[j];
                ans += mp[-sum];
            }
        }

        return ans;
    }
};