class Solution {
public:
    string getSmallestString(int n, int k){
        string ans(n,'a');
        k = k - n;

        int i = n - 1;
        while(i >= 0 and k){
            if(k > 25){
                k = k - 25;
                ans[i] = 'z';
            }
            else{
                ans[i] += k;
                k = 0;
            }
            i--;
        }

        return ans;
    }
};