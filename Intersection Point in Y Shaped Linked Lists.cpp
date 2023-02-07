//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
int len(Node* head){
    int len=0;
    Node* ptr=head;
    while(ptr!=NULL){
        len++;
        ptr=ptr->next;
    }
    return len;
}
    int intersectPoint(Node* head1, Node* head2)
    {
        if(head1==NULL||head2==NULL)return -1;
        
        // Your Code Here
        int l1=len(head1),l2=len(head2);
        Node* ptr1=head1,*ptr2=head2;
        if(l1>l2){
            int c=l1-l2;
            while(c--){
                ptr1=ptr1->next;
            }
            while(ptr1!=ptr2&&ptr1!=NULL&&ptr2!=NULL){
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            if(ptr1==ptr2)return ptr1->data;
            return -1;
        }else {
            int c=l2-l1;
            while(c--){
                ptr2=ptr2->next;
            }
            while(ptr1!=ptr2&&ptr1!=NULL&&ptr2!=NULL){
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            if(ptr1==ptr2)return ptr1->data;
            return -1;
        }
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends