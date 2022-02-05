// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B){
        int n = A.length();
        int m = B.length();
    
        if(n != m) return -1;
        vector<int> count(58);
    
        for(int i = 0;i<n;i++){
            count[A[i] - 'A']++;
            count[B[i] - 'A']--;
        }
    
        for(auto &i:count){
            if(i != 0) return -1;
        } 
    
        int b = n - 1;
    
        for(int i = n - 1;i>=0;i--){
            if(A[i] == B[b]) b--;
        }
    
        return b + 1;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends