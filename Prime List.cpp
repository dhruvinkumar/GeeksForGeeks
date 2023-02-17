//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:

    bool isprime(int n){
        if(n==0||n==1)return false;
        if(n==2||n==3)return true;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)return false;
        }return true;
    }
    int l(int n){
        // if(l==2)return 2;
        if(isprime(n)){
            return n;
        }
        l(n-1);
    }
    int r(int n){
        if(isprime(n)){
            return n;
        }
        r(n+1);
    }
    

    Node *primeList(Node *head){
        
        Node* ptr=head;
        while(ptr){
            int n=ptr->val;
            if(n==0)ptr->val=0;
            else{
            if(n==1){
                ptr->val=2;
            }
            else{
            if(!isprime(n)){
               int left=l(n-1); 
               int right=r(n+1); 
               
               if((n-left)<=(right-n))ptr->val=left;
               else ptr->val=right;
            }
            }
            }
            ptr=ptr->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends