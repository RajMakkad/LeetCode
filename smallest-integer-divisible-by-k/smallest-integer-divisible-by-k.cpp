class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 1) return 1;
        int pre = 1;
        
        for(int i = 2;i<=k;i++){
            pre = (pre*10 + 1)%k;
            if(pre == 0) return i;
        }
        
        return -1;
    }
};