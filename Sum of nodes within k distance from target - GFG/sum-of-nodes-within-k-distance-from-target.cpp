// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends

class Solution{
public:
     void parentNode(Node* root, unordered_map<Node*, Node*>& mp, Node* parent){
        if(root==NULL) return;
        mp[root]=parent;
        parentNode(root->left,mp,root);
        parentNode(root->right,mp,root);
    }
    Node* getTargetNode(Node* root, int target){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp->data == target) return temp;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    void findSum(Node* tar, int& sum, int i, int k, unordered_map<Node*,Node*>& mp,unordered_set<int>& st){
        if(i>k) return;
        if(tar==NULL) return;
        if(st.find(tar->data) != st.end()) return;
        sum+=tar->data;
        st.insert(tar->data);
        findSum(mp[tar],sum,i+1,k,mp,st);

        findSum(tar->left,sum,i+1,k,mp,st);
        
        findSum(tar->right,sum,i+1,k,mp,st);
    }
    int sum_at_distK(Node* root, int target, int k)
    {
        unordered_map<Node* , Node*> mp;
        Node* parent=NULL;
        parentNode(root,mp,parent);
        Node* tar = getTargetNode(root,target);
        int sum=0;
        Node* called=NULL;
        unordered_set<int> st;
        findSum(tar,sum,0,k,mp,st);
        return sum;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends