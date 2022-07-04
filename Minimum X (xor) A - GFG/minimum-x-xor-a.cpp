// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int x = __builtin_popcount(a);
        int y = __builtin_popcount(b);
        
        int ans = a;
        
        int d = abs(x - y);
        if(x > y){
            for(int i = 0;i<30 and d;i++){
                int p = 1<<i;
                if((a & p)){
                    ans = ans - p;
                    d--;
                } 
            }
        }
        else {
            for(int i = 0;i<30 and d;i++){
                int p = 1<<i;
                if((a & p) == 0){
                    ans += p;
                    d--;
                } 
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends