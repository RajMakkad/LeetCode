// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> a){
        int l = n - 1;
        int r = -1;
        for(int i = n - 2;i>=0;i--){
            if(a[i] < a[i + 1]){
                l = i;
                break;
            }
        }

        if(l == n - 1){
            reverse(a.begin(),a.end());
            return a;
        }

        for(int i = l + 1;i<n;i++){
            if(a[i] > a[l]){
                if(r = -1) r = i;
                else if(a[r] > a[i]) r = i;
            }
        }

        swap(a[l],a[r]);
        sort(a.begin() + l + 1,a.end());
        return a;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends