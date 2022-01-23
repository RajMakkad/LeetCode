class Solution {
public:
    int countPrimes(int n){
        int count = 0;
        vector<int> prime(n + 1,1);
        
        for(int i = 2;i<n;i++){
            if(prime[i] == 0) continue;
            count++;
            for(long long s = (long long)i*i ; s <= n ; s += i){
                prime[s] = 0;
            }
        }
        
        return count;
    }
};