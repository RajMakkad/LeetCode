// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    map<char, int> cnt, sub;
    public:
    int findSubString(string str){
        int n = str.length();
    
        for(int i = 0;i<n;i++){
            cnt[str[i]]++;
        }
    
        int ans = n;
        int s = 0;
    
        for(int i = 0;i<n;i++){
            sub[str[i]]++;
    
            while((int)cnt.size() == (int)sub.size()){
                ans = min(ans,i - s + 1);
                sub[str[s]]--;
                
                if(sub[str[s]] == 0) sub.erase(str[s]);
                s++;
            }
        }
    
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends