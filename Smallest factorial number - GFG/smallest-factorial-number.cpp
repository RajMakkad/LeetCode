// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    bool isPossible(int x, int n){
        int ans = 0;

        for(int i = 5;i<=x;i *= 5){
            ans += x/i;
        }

        return ans >= n;
    }
    public:
    int findNum(int n){
        int s = 5;
        int e = n * 5;
        int m = s + (e - s)/2;

        while(e >= s){
            m = s + (e - s)/2;
            if(isPossible(m, n)) e = m - 1;
            else s = m + 1;
        }

        return s;
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends