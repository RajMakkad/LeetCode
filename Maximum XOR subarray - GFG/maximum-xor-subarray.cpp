// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++



class Solution{  
    struct Node{
        Node *links[2];
        
        bool is_present(int p){
            return links[p] != NULL;
        }
        
        void insert(int p){
            links[p] = new Node();
        }
        
        Node *get(int p){
            return links[p];
        }
    };
    
    Node *root = new Node();
    
    void add(int num){
        Node *node = root;
        for(int i = 31;i>=0;i--){
            int p = (num>>i)&1;
            
            if(node->is_present(p) == false){
                node->insert(p);
            }
            node = node->get(p);
        }
    }
    
    int getXor(int num){
        Node *node = root;
        int ans = 0;
        
        for(int i = 31;i>=0;i--){
            int p = (num>>i)&1;
            if(node->is_present(!p)){
                ans |= 1<<i;
                node = node->get(!p);
            }
            else node = node->get(p);
        }
        
        return ans;
    }
public:
    int maxSubarrayXOR(int n, int a[]){
        vector<int> p(n);
        
        p[0] = a[0];
        add(p[0]);
        int ans = p[0];
        
        for(int i = 1;i<n;i++){
            p[i] = p[i - 1]^a[i];
            add(p[i]);
            ans = max({ans,p[i],getXor(p[i])});
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
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends