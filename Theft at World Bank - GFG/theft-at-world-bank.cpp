// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	#define ll long long
long double maximumProfit(int n, long long c, vector<long long> w, vector<long long> p){
    vector<pair<long double,ll>> a;
    long double d = 0.0;
    

    for(int i = 0;i<n;i++){
        ll x = sqrt(w[i]);
        if(x * x != w[i]){
            d = (p[i]*1.0/w[i]*1.0);
            a.push_back({d,w[i]});
        }
    }

    sort(a.begin(),a.end());
    n = a.size();
    d = 0.0;
    long double ans = 0.0;

    for(int i = n - 1;i>=0;i--){
        d = min(c,a[i].second);
        c = c - d;
        
        ans += (long double)(a[i].first * d);
    }

    return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends