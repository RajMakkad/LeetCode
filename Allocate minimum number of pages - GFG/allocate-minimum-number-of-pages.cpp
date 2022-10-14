// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define ll long long int

class Solution {
    bool is_possible(ll need, int a[], int n, int m){
        ll cast = 0;
        for(int i = 0;i < n;i++){
            cast += a[i];
            if(cast > need){
                cast = a[i];
                m--;
            }
            else  if(cast == need){
                cast = 0;
                m--;
            }
        }
        
        m = cast > 0 ? m - 1: m;
        return m >= 0;
    }
    public:
    
    int findPages(int a[], int n, int m) {
        if(m > n) return -1;
        
        ll s = a[n - 1];
        ll e = 1e11;
        ll mid = s + (e - s)/2;
        
        while(e >= s){
            mid = s + (e - s)/2;
            if(is_possible(mid, a, n, m)) e = mid - 1;
            else s = mid + 1;
        }
        
        return s;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends