#define ll long long int
#define pi pair<ll,int>
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<ll> idx(m,0), ans;
        ans.push_back(1);

        priority_queue<pi,vector<pi>,greater<pi>> q;
        for(int i = 0;i<m;i++){
            q.push({primes[i],i});
        }

        while(ans.size() < n){
            auto u = q.top();
            q.pop();

            if(ans.back() != u.first) ans.push_back(u.first);
            idx[u.second]++;
            q.push({primes[u.second]*ans[idx[u.second]],u.second});
        }

        return ans[n - 1];
    }
};