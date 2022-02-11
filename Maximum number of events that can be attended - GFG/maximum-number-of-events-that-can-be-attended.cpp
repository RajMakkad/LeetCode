// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxEvents(int start[], int end[], int n){
        
        vector<pair<int,int>> a(n);
        for(int i=0; i<n; i++){
            a[i].first = start[i];
            a[i].second = end[i];
        }
        sort(a.begin(),a.end());
        
        int i = 0;
        int d = 0;
        int ans = 0;
        
        priority_queue<int> q;
        
        
        while(i < n || q.size()){
            if(q.empty()) d = a[i].first;
            while(i < n and d >= a[i].first){
                q.push(-a[i++].second);
            }
            
            ans++;
            d++;
            q.pop();
            
            while(q.size() and d > -q.top()) q.pop();
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
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}  // } Driver Code Ends