class Solution {
    bool binarySearch(vector<int> &a, int &x){
        int s = 0;
        int e = a.size() - 1;
        int m = s + (e - s)/2;
        while(e >= s){
            m = s + (e - s)/2;
            if(a[m] == x) return true;
            else if(a[m] > x) e = m - 1;
            else s = m + 1;
        }

        return false;
    }
public:
    int findKthPositive(vector<int>& a, int k) {
        int x = 1;
        while(k > 0){
            if(!binarySearch(a,x)) k--;
            if(k == 0) break;
            x++;
        }

        return x;
    }
};