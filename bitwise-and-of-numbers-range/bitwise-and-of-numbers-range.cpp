class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;

        while(left!=right){
            left/=2;
            right/=2;
            cnt++;
        }

        int ans = left<<cnt;
        return ans;
    }
};