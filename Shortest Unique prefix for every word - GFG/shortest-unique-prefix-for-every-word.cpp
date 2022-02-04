// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    struct Node{
        Node *links[26];
        int p = 0;
    };
    Node *root = new Node();

    void add(string &s){
        Node *node = root;
        for(auto &i:s){
            if(node->links[i - 'a'] == NULL){
                node->links[i - 'a'] = new Node();
            }
            node = node->links[i - 'a'];
            node->p++;
        }
    }

    string getUnique(string &s){
        Node *node = root;
        string str = "";
        for(auto &i:s){
            str += i;
            node = node->links[i - 'a'];
            if(node->p == 1) break;
        }

        return str;
    }

    public:
    vector<string> findPrefixes(string a[], int n){
        vector<string> ans;
        for(int i = 0;i<n;i++){
            add(a[i]);
        }

        for(int i = 0;i<n;i++){
            string s = getUnique(a[i]);
            ans.push_back(s);
        }

        return ans;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends