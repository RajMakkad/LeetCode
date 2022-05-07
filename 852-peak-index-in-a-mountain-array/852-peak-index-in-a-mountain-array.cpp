class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        int s = 0;
        int e = n - 1;
        int m = s + (e - s)/2;
        
        while(e >= s){
            m = s + (e - s)/2;
            if(a[m + 1] > a[m]) s = m + 1;
            else if(a[m + 1] < a[m]) e = m - 1;
        }
        
        return s;
    }
};