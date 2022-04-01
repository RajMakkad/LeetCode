// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 



 // } Driver Code Ends


class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n){ 
        vector<pair<int,int>> a(n,{0,0});
        set<int> st;

        for(int i = 0;i<n;i++){
            st.insert(arr[i]);
            auto l = st.lower_bound(arr[i]);
            l--;
            a[i].first = *l;
        }

        int maxx = 0;
        for(int i = n - 1;i>=0;i--){
            maxx = max(maxx,arr[i]);
            a[i].second = maxx;
        }

        vector<int> ans;
        long long int p = 0;

        for(int i = 1;i<n - 1;i++){
            if(a[i].first < arr[i] and arr[i] < a[i].second){
                long long int sub = 1LL*a[i].first * arr[i] * a[i].second;
                if(sub >= p){
                    p = sub;
                    ans = {a[i].first,arr[i],a[i].second};
                }
            }
        }

        if(ans.empty()) return {-1};
        return ans;
    } 

};

// { Driver Code Starts.
// Driver Program 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; ++i)
	        cin>>arr[i];
	    
	    vector<int> res;
	    Solution obj;
	    res = obj.maxProductSubsequence(arr, num);
	    
	    if(res[0] == -1)
	        cout<<"Not Present\n";
	    else{
    	    for(int i = 0; i<3; ++i)
    	        cout<<res[i]<<" ";
    	    cout<<"\n";
	    }
	    
	}
} 
  // } Driver Code Ends