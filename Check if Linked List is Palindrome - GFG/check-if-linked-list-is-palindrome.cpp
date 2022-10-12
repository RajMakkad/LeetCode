//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends

class Solution{
  public:
    int size(Node *node){
        if(!node) return 0;
        return size(node->next) + 1;
    }
    
    Node* reverse(Node *node){
        Node *pre = NULL;
        while(node){
            Node *next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }
        
        return pre;
    }
    
    bool isPalindrome(Node *head){
        int n = size(head);
        int move = (n + 1)/2;
        
        Node *ref = head;
        while(move--) ref = ref->next;
        
        ref = reverse(ref);
        while(head and ref){
            if(head->data != ref->data) return false;
            head = head->next;
            ref = ref->next;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends