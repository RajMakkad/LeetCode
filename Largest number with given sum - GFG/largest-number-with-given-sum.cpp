// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution{
    public:
    string largestNumber(int n, int sum){
        if(n * 9 < sum) return "-1";
        string ans(sum/9,'9');
        if(sum % 9 != 0) ans += ((sum % 9) + '0');
        
        ans += string(n - ans.size(),'0');
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends