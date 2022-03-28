// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:    
   int swapBits(int x, int p1, int p2, int n){
       bitset<32> st(x);
       for(int i = 0; i<n; i++){
           int t = st[p1 + i];
           st[p1 + i] = st[p2 + i];
           st[p2 + i] = t;
       }
       
       return st.to_ullong();
   }
};

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,p1,p2,n;
		cin>>x>>p1>>p2>>n;
		Solution obj;
		int res=obj.swapBits(x,p1,p2,n);
		printf("%d\n", res);
	}
    return 0;
}  // } Driver Code Ends