// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
class Solution{
  public:
    string multiplyStrings(string s1, string s2) {
        int sign = 0;
        
        if(s1[0] == '-'){
            sign++;
            s1.erase(s1.begin());
        }
        
        if(s2[0] == '-'){
            sign++;
            s2.erase(s2.begin());
        }
        
        int n = s1.length(), m = s2.length();
        string ans(n + m, '0');
        
        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                int sum = (s1[i] - '0') * (s2[j] - '0') + (ans[i + j + 1] - '0');
                ans[i + j + 1] = sum % 10 + '0';
                ans[i + j] += sum / 10;
            }
        }
        
        for(int i = 0;i < n + m;i++){
            if(ans[i] != '0'){
                if(sign == 1) return '-' + ans.substr(i);
                else return ans.substr(i);
            }
        }
        
        return "0";
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends