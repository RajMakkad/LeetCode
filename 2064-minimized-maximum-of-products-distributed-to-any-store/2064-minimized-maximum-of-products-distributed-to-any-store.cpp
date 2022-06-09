class Solution {
    bool isPossible(int n, int m, vector<int>& q){
        int cnt = 0;
        for(int i:q) cnt += (i + m - 1)/m;
        
        return n >= cnt;
    }
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int s = 1;
        int e = 100000;
        int m = s + (e - s)/2;
        
        while(e >= s){
            m = s + (e - s)/2;
            if(isPossible(n, m, q)) e = m - 1;
            else s = m + 1;
        }
        
        return s;
    }
};