// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool check(string &s, string &str){
        string sub = str;
        while(s.length() > sub.length()) sub += str;
        return s == sub;
    }
    int isRepeat(string s){
        int n = s.length();
        string str = "";
    
        for(int i = 0;i<n - 1;i++){
            str += s[i];
            if(n % (i + 1) == 0){
                if(check(s, str)){
                    return true;
                }
            }
        }
    
        return false;
    }	
	
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends