class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2;
        int low = 0, high = min(n1, left);
        
        while (low <= high) {
            int mid1 = (low + high + 1) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1 and mid1 >= 0)
                r1 = nums1[mid1];
            if (mid2 < n2 and mid2 >= 0)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0 and mid1 <= n1)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0 and mid2 <= n2)
                l2 = nums2[mid2 - 1];
            
            if (l1 > r2) {
                // Move towards the left side of nums1
                high = mid1 - 1;
            }
            else if (r1 < l2) {
                // Move towards the right side of nums1
                low = mid1 + 1;
            }
            else if (n % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            
        }
        
        return 0; // If the code reaches here, the input arrays were not sorted.
    }
};