// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int a[], int n, int k){
       sort(a,a + n);
       vector<int> suff(n,0);
       int sum = 0;

       for(int i = n - 1;i>=0;i--){
           sum += a[i];
           suff[i] = sum;
       }

       int ans = 1e9;
       sum = 0;
       for(int i = 0;i<n;i++){
           auto u = upper_bound(a,a + n,a[i] + k) - a;
           int cnt = sum;
           if(u != n) cnt = cnt + suff[u] - (n - u)*(a[i] + k);

           ans = min(ans,cnt);
           sum += a[i];
       }

       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends