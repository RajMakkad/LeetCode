// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

#define ll long long int
class Solution{
public:
    int isPossible(long long s, long long n, long long x, long long arr[]){
        vector<ll> a;
        a.push_back(s);

        ll sum = s;
        for(int i = 0;i<n;i++){
            ll e = sum + arr[i];
            if(e > x) break;
            a.push_back(e);
            
            sum += e;
        }
        
        n = a.size() - 1;
        for(int i = n;i>=0;i--){
            if(x >= a[i]){
                x = x - a[i];
            }
        }

        return x == 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends