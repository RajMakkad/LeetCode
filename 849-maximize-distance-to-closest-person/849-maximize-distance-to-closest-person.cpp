class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int ans = 0;
        int cnt = -1;

        for(int i = 0;i<n;i++){
            if(seats[i]){
                if(cnt == -1) ans = max(ans,i);
                ans = max(ans,(i - cnt)/2);
                cnt = i;
            }
        }

        ans = max(ans,n - cnt - 1);
        return ans;
    }
};