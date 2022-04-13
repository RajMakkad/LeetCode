class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<long long> fib;
        long long f1 = 1;
        long long f2 = 1;

        while(k >= f2){
            fib.push_back(f2);
            long long s = f2;
            f2 += f1;
            f1 = s;
        }

        int ans = 0;
        int n = fib.size();

        for(int i = n - 1;i>=0;i--){
            while(k >= fib[i]){
                ans++;
                k = k - fib[i];
            }
        }
        return ans;
    }
};