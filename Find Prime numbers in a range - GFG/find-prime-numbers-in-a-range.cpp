// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int m, int n) {
        vector<int> range(n + 1,1);
        range[1] = 0;

        for(int i = 2;i*i<=n;i++){
            if(range[i] == 0) continue;
            for(int p = i*i;p<=n;p += i){
                range[p] = 0;
            }
        }

        vector<int> prime;
        for(int i = m;i<=n;i++){
            if(range[i]) prime.push_back(i);
        }

        return prime;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends