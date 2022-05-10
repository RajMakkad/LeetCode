// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;
        int e = n;
        
        while(e >= s){
            int m = s + (e - s)/2;
            if(isBadVersion(m)) e = m - 1;
            else s = m + 1;
        }

        return s;
    }
};