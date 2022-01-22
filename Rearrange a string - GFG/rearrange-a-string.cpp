// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    string arrangeString(string str){
        int sum = 0;
        vector<int> count(26,0);
        for(auto &i:str){
            if(isdigit(i)) sum += (i - '0');
            else count[i - 'A']++;
        }

        str = "";
        for(int i = 0;i<26;i++){
            char c = 'A' + i;
            while(count[i]--) str += c;
        }

        if(sum) str += to_string(sum);
        return str;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends