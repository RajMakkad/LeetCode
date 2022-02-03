// { Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int n){
        string s = "";
        int count = 0;
        while(n > 0){
            count = n%26;
            if(count == 0) count = 26;
            
            s += ('A' + count - 1);
            n = n - count;
            n /= 26;
        }

        reverse(s.begin(),s.end());
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
      // } Driver Code Ends