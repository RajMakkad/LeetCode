class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int x = n + m - 1;
        n--, m--;
        while(n >= 0 || m >= 0){
            if(n >= 0 and m >= 0){
                if(nums1[n] < nums2[m]){
                    swap(nums1[x],nums2[m]);
                    m--;
                }
                else{
                    swap(nums1[n],nums1[x]);
                    n--;
                }
            }
            else if(n >= 0) swap(nums1[n--],nums1[x]);
            else swap(nums2[m--],nums1[x]);
            x--;
        }
    }
};