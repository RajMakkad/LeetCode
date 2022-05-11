class Solution {
public:
    int arrangeCoins(int n) {
        int s = 1;
        int e = n;
        long long m = s + (e - s)/2;
        
        while(e >= s){
            m = s + (e - s)/2;
            long long sCase = m*(m + 1)/2;
            if(sCase > n) e = m - 1;
            else s = m + 1;
        }
        
        return e;
    }
};