// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    int count(int x,vector<int> &a){
        int cnt = 0;
        int n = a.size();
        
        for(int i = 0;i<n;i++){
            if((a[i] & x) != x) cnt++;
        }
        
        return cnt;
    }
    public:
    int count(int n, vector<int> a,int x){
        int ans = n;
        
        for(int i = 0;i<31;i++){
            int f = (x >> i);
            if((f & 1) == 0){
                int sub = (1<<i);
                int num = (x|sub);
                sub--;
                num = (num|sub) - sub;
                ans = min(ans,count(num,a));
            }
        }
        
        return ans;
    }
};
// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends