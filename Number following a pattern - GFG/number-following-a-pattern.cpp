// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        int n = S.length();
        string ans = "";
        int i = 0;

        while(i<n and S[i] == 'D') i++;
        ans += ('1' + i);

        for(i = 0;i<n;i++){
            if(S[i] == 'D') ans += (ans.back() - 1);
            else{
                char c = ('2' + i);
                int k = i + 1;
                while(k<n and S[k] == 'D') k++;
                c += (k - i - 1);
                ans += c;
            }
        }

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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends