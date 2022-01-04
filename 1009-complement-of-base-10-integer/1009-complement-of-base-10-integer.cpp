class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        long long x = log2(n) + 1;
        x = 1<<x;
        x--;
        
        return x^n;
    }
};