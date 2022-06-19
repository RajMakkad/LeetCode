// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution{
    void reverse(Node *s, Node *e){
        
        Node *pre = NULL, *curr = s;
        e->next = NULL;
        while(curr){
            Node *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
    }
    public:
    Node* reverseBetween(Node* head, int n, int m){
        Node *s = head, *e = head, *p = NULL;
        
        int x = n - 1;
        while(x-- > 0){
            p = s;
            s = s->next;
        }
        
        x = m - 1;
        while(x-- > 0){
            e = e->next;
        }
        
        Node *next = e->next;
        reverse(s, e);
        
        s->next = next;
        if(p) p->next = e;
        else return e;
        
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends