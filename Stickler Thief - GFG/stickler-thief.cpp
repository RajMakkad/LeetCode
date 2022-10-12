//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution{
    public:
    
    int FindMaxSum(int arr[], int n){
        int sum1 = arr[0];
        int sum2 = 0;
        
        for(int i = 1;i < n;i++){
            int sub = sum1;
            sum1 = max(sum1, arr[i] + sum2);
            sum2 = max(sum2, sub);
        }
        
        return max(sum1, sum2);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends