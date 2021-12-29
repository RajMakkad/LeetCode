class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sum1 = 0;
        int sum2 = 0;
        int q1 = 0;
        int q2 = 0;
        
        for(int i = 0;i<n;i++){
            if(num[i] == '?'){
                if(i<n/2) q1++;
                else q2++;
            }
            else{
                if(i<n/2) sum1 += (num[i] - '0');
                else sum2 += (num[i] - '0');
            }
        }
        
        if((q1 + q2)%2) return true;
        
        if(sum1 == sum2){
            if(q1 == q2) return false;
            else return true;
        }
        else if(sum1 > sum2){
            int diff = sum1 - sum2;
            if(q1 < q2 and diff == 9*(q2 - q1)/2) return false;
            else return true;
        }
        else{
            int diff = sum2 - sum1;
            if(q1 > q2 and diff == 9*(q1 - q2)/2) return false;
            else return true;
        }
    }
};