// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    bool is_possible(int a[],int n,int cap,int d){
        int c = cap;
        for(int i = 0;i<n;i++){
            if(a[i] > cap) return false;
            if(c >= a[i]) c = c - a[i];
            else{
                c = cap - a[i];
                d--;
            }
        }

        return d > 0;
    }
  public:
    int leastWeightCapacity(int a[], int n, int d){
        int s = 1;
        int e = 1e9;
        int m = s + (e - s)/2;

        while(e >= s){
            m = s + (e - s)/2;
            if(is_possible(a,n,m,d)) e = m - 1;
            else s = m + 1;
        }
        return s;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends