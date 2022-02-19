class Solution {
    int check(int m,vector<int> &a,int n){
        int cnt = 0;
        
        for(int i = 0;i<n;i++){
            int u = upper_bound(a.begin(),a.end(),a[i] + m) - a.begin();
            cnt += (u - i - 1);
        }

        return cnt;
    }
public:
    int smallestDistancePair(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int n = a.size();
        int s = a[n - 1] - a[0];
        for(int i = 1;i<n;i++) s = min(s,a[i] - a[i - 1]);

        int e = a[n - 1] - a[0];
        int m = s + (e - s)/2;

        while(e >= s){
            m = s + (e - s)/2;
            int cnt = check(m,a,n);
        
            if(k > cnt) s = m + 1;
            else e = m - 1;
        }

        return s;
    }
};