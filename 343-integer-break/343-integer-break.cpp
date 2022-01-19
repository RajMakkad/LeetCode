class Solution {
    int power(long long num,int p){
        int result = 1;
        while(p){
            if(p%2) result = result*num;
            num = num*num;
            p /= 2;
        }
        return result;
    }
    
public:
    int integerBreak(int n) {
        
        if(n == 2) return 1;
        else if(n == 3) return 2;
        else if(n%3 == 0) return power(3,n/3);
        else if(n%3 == 1) return power(3,(n - 4)/3)*4;
        else return power(3,n/3)*2;
    }
};