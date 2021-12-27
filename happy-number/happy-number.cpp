class Solution {
    int nextNumber(int n){
        int sum = 0;
        while(n){
            int lastDigit = n%10;
            sum += lastDigit*lastDigit;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do{
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
            if(fast==1) return true;
        }
        while(slow!=fast);
        return false;
    }
};