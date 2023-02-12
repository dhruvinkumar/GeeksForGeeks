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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
and a pointer to right child */
/*struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to check whether a binary tree is foldable or not.

    void pre1(Node* root,vector<Node*>& v){
        if(root==NULL)return ;
        v.push_back(root->left);
        v.push_back(root->right);
        pre1(root->left,v);
        pre1(root->right,v);
    }
    void pre2(Node* root,vector<Node*>& v){
        if(root==NULL)return ;
        v.push_back(root->right);
        v.push_back(root->left);
         pre2(root->left,v);
        pre2(root->right,v);
    }



bool IsFoldable(Node* root)
{
    // Your code goes here
    if(root==NULL || !root->left&&!root->right)return true;
    if(root->left&&!root->right ||!root->left&&root->right)return false;
    vector<Node*> v1;
    vector<Node*> v2;
    pre1(root->left,v1);
    pre2(root->right,v2);
    if(v1.size()!=v2.size())return false;
    
    for(int i=0;i<v1.size();i++){
        if(v1[i]&&!v2[i] || !v1[i]&&v2[i])return false;
    }
    return true;
    
}

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        if (IsFoldable(root)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

    }


    return 0;
}
// } Driver Code Ends