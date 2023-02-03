//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int L = 1e6 + 1;

class Solution {
    int prime[L];
    void seive(int n){
        for(int i = 2;i <= n;i++)
            prime[i] = 1;
        
        for(int i = 2;i * i <= n;i++){
            if(prime[i] == 0)
                continue;
            for(int j = i * i;j <= n;j += i){
                prime[j] = 0;
            }
        }
    }
  public:
    vector<int> getPrimes(int n) {
        seive(n);
        for(int i = 2;i <= n/2;i++){
            if(prime[i] and prime[n - i]){
                return {i, n - i};
            }
        }
        
        return {-1, -1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<int> ptr = ob.getPrimes(N);
        cout << ptr[0]<<" "<<ptr[1] << endl;
    }
    return 0;
}
// } Driver Code Ends