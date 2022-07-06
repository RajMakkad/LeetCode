class Solution {
public:
    int fib(int n) {
        if(1 >= n) return n;
        int last = 1, slast = 0;
        
        for(int i = 2;i<=n;i++){
            int d = last;
            last += slast;
            slast = d;
        }
        return last;
    }
};