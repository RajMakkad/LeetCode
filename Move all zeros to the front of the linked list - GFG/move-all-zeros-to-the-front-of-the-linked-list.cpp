// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void moveZeroes(struct Node **head);

// function to displaying nodes
void display(struct Node *head) {
    while (head != NULL) {
	    cout << head->data << " ";
	    head = head->next;
    }
    cout <<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q;
        struct Node *Head=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>q;
            push(&Head,q);
        }
        moveZeroes(&Head);
        display(Head);

    }
}
// } Driver Code Ends


void moveZeroes(struct Node **head)
{
    //Your code here
    
    int cnt = 0;
    
    while((*head) and (*head)->data == 0)
        (*head) = (*head)->next, cnt++;
    
    Node * cur = (*head);
    
    while(cur and cur->next){
        if(cur->next->data == 0)
            cur->next = cur->next->next, cnt++;
        else
            cur = cur->next;
    }
    
    while(cnt--)
    {
        Node * newNode = new Node(0);
        newNode->next = (*head);
        
        (*head) = newNode;
    }
}