class Solution {
public:
    int findComplement(int num) {
        long long x = log2(num);
        x = 1<<(x + 1);
        x--;
        return num^x;
    }
};