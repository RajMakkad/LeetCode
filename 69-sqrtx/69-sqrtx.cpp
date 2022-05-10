class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long m = s + (e - s)/2;

        while(e >= s){
            m = s + (e - s)/2;
            if(m * m > x) e = m - 1;
            else s = m + 1;
        }

        return e;
    }
};