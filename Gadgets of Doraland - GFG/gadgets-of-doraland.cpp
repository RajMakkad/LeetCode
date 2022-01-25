// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
  
class Solution{
    static bool comp(const pair<int,int> &a,const pair<int,int> &b){
        if(a.first == b.first) return a > b;
        return a > b;
    }
    public:
    vector<int> TopK(vector<int>& a, int k){
        unordered_map<int,int> count;
        for(auto i:a) count[i]++;
        vector<pair<int,int>> v;

        for(auto &i:count) v.push_back({i.second,i.first});
        sort(v.begin(),v.end(),comp);
        vector<int> ans;

        for(int i = 0;i<k;i++) ans.push_back(v[i].second);
        return ans;
    }
};
// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends