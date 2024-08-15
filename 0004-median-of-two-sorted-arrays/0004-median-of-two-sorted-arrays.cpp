class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int left = (n + m + 1)/2;
        int s = 0, e = min(n, left);
        while(e >= s){
            int mid = (s + e + 1)/2;
            int rem = left - mid;
            int l1 = mid > 0 ? nums1[mid - 1] : INT_MIN;
            int l2 = (left - mid > 0  and left - mid <= m)? nums2[left - mid - 1] : INT_MIN;
            int r1 = mid < n ? nums1[mid] : INT_MAX;
            int r2 = (left - mid < m  and left - mid >= 0)? nums2[left - mid] : INT_MAX;
            // cout<<mid<<" "<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<"\n";
            
            if(rem > m)
                s = mid + 1;
            else if(l1 > r2)
                e = mid - 1;
            else if(r1 < l2)
                s = mid + 1;
            else if((n + m) % 2)
                return 1.0 * max(l1, l2);
            else
                return 1.0 * (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        return 0.0;
    }
};