// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    set<vector<int>> s;
    void generate(int idx,vector<int> &sub,vector<int> &a){
        int n = a.size();
        if(idx == n){
            sort(sub.begin(),sub.end());
            s.insert(sub);
            return ;
        }
    
        sub.push_back(a[idx]);
        generate(idx + 1,sub,a);
        sub.pop_back();
    
        generate(idx + 1,sub,a);
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n){
        vector<int> sub;
        sort(arr.begin(),arr.end());
        generate(0,sub,arr);
    
        vector<vector<int>> ans;
        for(auto i:s) ans.push_back(i);
    
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends