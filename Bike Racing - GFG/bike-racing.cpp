// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    bool minHour(long mid, long n, long m, long l, long h[], long a[]){
        for(int i = 0;i<n;i++){
            long v = h[i] + a[i]*mid;
            if(v >= l) m = m - v;
        }

        return m <= 0;
    }

public:
    long buzzTime(long n, long m, long l, long h[], long a[]){
        long s = 0;
        long e = max(l,m);
        long mid = s + (e - s)/2;

        while(e >= s){
            mid = s + (e - s)/2;
            if(minHour(mid,n,m,l,h,a)) e = mid - 1;
            else s = mid + 1;
        }

        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends