// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    string reverseWords(string s){ 
    vector<string> v;
    string s1 ="";
    
    for(int i = 0;i<s.length();i++){
        if(s[i] != '.') s1 += s[i];
        else 
        {
            v.push_back(s1);
            s1 = "";
        }
    }
    
    v.push_back(s1);
    s1 = "";
    
    for(int i = v.size() - 1;i>=0;i--){
        s1 += v[i];
        if(i!=0) s1+='.';
    }
    
    return s1;
} 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends