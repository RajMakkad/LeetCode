// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int countDistinctSubarray(int arr[], int n){
        unordered_map<int, int> mp, mSub;
        
        for(int i = 0;i < n;i++){
            mp[arr[i]]++;
        }
        
        int count = 0;
        int start = 0;
        int m = mp.size();
        
        for(int e = 0;e < n;e++){
            mSub[arr[e]]++;
            while((int)mSub.size() == m){
                mSub[arr[start]]--;
                if(mSub[arr[start]] == 0){
                    mSub.erase(arr[start]);
                }
                
                start++;
            }
            
            count += (e - start + 1);
        }
        
        return (n * (n + 1))/2 - count;
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends