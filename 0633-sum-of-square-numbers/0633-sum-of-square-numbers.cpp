class Solution {
    bool isPerfectSquare(long double x) {
    if (x >= 0) {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
public:
    bool judgeSquareSum(int c) {
        for(long long i = 0; i * i <= c; i++){
            if(isPerfectSquare(c - i * i))
                return true;
        }
        return false;
    }
};