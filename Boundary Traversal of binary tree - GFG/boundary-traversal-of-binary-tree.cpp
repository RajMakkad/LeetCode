// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
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

class Solution {
    void solve(Node *node, int type, vector<int> &v){
        if(!node) return ;
        
        if(type == 1){
            if(node->left || node->right) v.push_back(node->data);
            
            if(node->left) solve(node->left, type, v);
            else solve(node->right, type, v);
        }
        else if(type == 2) {
            if(node->right) solve(node->right, type, v);
            else solve(node->left, type, v);
            
            if(node->left || node->right) v.push_back(node->data);
        }
        else {
            solve(node->left, type, v);
            solve(node->right, type, v);
            
            if(!node->left and !node->right) v.push_back(node->data);
        }
    }
public:
    vector <int> boundary(Node *node){
        vector<int> left, leaf, right;
        
        if(!node->left and !node->right) return {node->data};
        else left.push_back(node->data);
        
        solve(node->left, 1, left);
        solve(node->right, 2, right);
        solve(node, 3, leaf);
        
        vector<int> ans;
        
        for(int i = 0;i < (int)left.size();i++){
            ans.push_back(left[i]);
        }
        
        for(int i = 0;i < (int)leaf.size();i++){
            ans.push_back(leaf[i]);
        }
        
        for(int i = 0;i < (int)right.size();i++){
            ans.push_back(right[i]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends