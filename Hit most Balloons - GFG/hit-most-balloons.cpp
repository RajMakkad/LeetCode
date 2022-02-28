// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mostBalloons(int n, pair<int,int> a[]){
        int ans = 1;

        for(int i = 0;i<n;i++){
            map<pair<int,int>,int> mp;
            int overlap = 0;
            for(int j = i;j<n;j++){
                int y = a[j].second - a[i].second;
                int x = a[j].first - a[i].first;

                if(a[i].first == a[j].first and a[i].second == a[j].second) overlap++;
                else{
                    int y = a[j].second - a[i].second;
                    int x = a[j].first - a[i].first;

                    if(x == 0) y = 1e9;
                    else if(y == 0) x = 1e9;

                    int g = __gcd(y,x);
                    x /= g;
                    y /= g;
                    mp[{y,x}]++;
                }
            }

            for(auto &m:mp){
                ans = max(ans,m.second + overlap);
            }
        }

        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends