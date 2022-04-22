// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int sum(int a , int b)
   {
       //code here
       int C=a&b;
       int sum=a^b;
       while(C>0){
           int Shift=C<<1;
           C=sum&Shift;
           sum=sum^Shift;
       } 
       return sum;
   }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends