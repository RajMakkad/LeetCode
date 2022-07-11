// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    bool pass(vector<int> &v){
        for(int i = 0;i < 26;i++){
            if(v[i] > 0) return false;
        }
        
        return true;
    }
    public:
    string smallestWindow (string s, string p){
        int n = s.length(), m = p.length();
        vector<int> model(26, 0);
        
        for(auto i:p){
            int x = i - 'a';
            model[x]++;
        }
        
        int st = 0;
        pair<int, int> ans = {n + 1, 0};
        for(int i = 0;i < n;i++){
            int x = s[i] - 'a';
            model[x]--;
            
            while(pass(model)){
                int size = i - st + 1;
                if(ans.first > size){
                    ans = {size, st};
                }
        
                model[s[st++] - 'a']++;
            }
        }
        
        return (ans.first == n + 1 ? "-1": s.substr(ans.second, ans.first));
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends