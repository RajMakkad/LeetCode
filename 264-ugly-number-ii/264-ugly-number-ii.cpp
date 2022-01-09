class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n + 1];
        ugly[1] = 1;

        int i2 = 2;
        int i3 = 2;
        int i5 = 2;
        int val2 = 2;
        int val3 = 3;
        int val5 = 5;

        for(int i = 2;i<=n;i++){
            int mini = min({val2,val3,val5});
            ugly[i] = mini;

            if(mini == val2) val2 = 2*ugly[i2++];
            if(mini == val3) val3 = 3*ugly[i3++];
            if(mini == val5) val5 = 5*ugly[i5++];
        }

        return ugly[n];
    }
};