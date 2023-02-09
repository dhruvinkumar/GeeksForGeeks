//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inOrder(Node *root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
// return the head of the DLL and remove those node from the tree as well.

    void pre(Node* root,vector<Node*>& v,Node* pr){
        if(root==NULL)return ;
        if(root->left==NULL&&root->right==NULL){
            Node* newnode=new Node(root->data);
            newnode->left=NULL;
            newnode->right=NULL;
            v.push_back(newnode);
            if(pr->left==root)pr->left=NULL;
            if(pr->right==root)pr->right=NULL;
            return ;
        }
        pre(root->left,v,root);
        pre(root->right,v,root);
    }

Node * convertToDLL(Node *root){
    // add code here.
    if(root==NULL)return NULL;
    vector<Node*> v;
    if(root->left==NULL&&root->right==NULL){
        
        return root;
    }
    pre(root->left,v,root);
    pre(root->right,v,root);
    int n=v.size();
    if(n==1)return v[0];
    v[0]->left=NULL;
    v[0]->right=v[1];
    v[n-1]->left=v[n-2];
    v[n-1]->right=NULL;
    for(int i=1;i<n-1;i++){
        v[i]->left=v[i-1];
        v[i]->right=v[i+1];
    }
    return v[0];
    
}

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Node* head = convertToDLL(root);
        inOrder(root);
        cout << "\n";
        Node *curr = head, *last = head;
        while (curr) {
            cout << curr->data << " ";
            last = curr;
            curr = curr->right;
        }
        cout << "\n";
        curr = last;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->left;
        }
        cout << "\n";
    }
    return 0;
}


// } Driver Code Ends