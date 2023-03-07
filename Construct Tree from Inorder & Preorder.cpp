//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
   Node *helper(int in[], int pre[], int &index, int s, int e,int size){
        if(index >= size || s>e){
            return NULL;
        }
        int ele = pre[index++];
        Node *root = new Node(ele);
        int pos = 0;
        
        for(int i=s; i<=e; i++){
            if(in[i] == ele){
                pos = i;
                break;
            }
        }
        
        root->left = helper(in, pre, index, s, pos-1, size);
        root->right = helper(in, pre, index, pos+1, e, size);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int index = 0;
        return helper(in, pre, index, 0, n-1, n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends