//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


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
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root==NULL)return 0;
        map<Node*,Node*> m;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* fn=q.front();
            
            if(fn->left){
                m[fn->left]=fn;
                q.push(fn->left);
            }
            if(fn->right){
                m[fn->right]=fn;
                q.push(fn->right);
            }
            q.pop();
        }
        
        Node* node;
        q.push(root);
        
        bool check =true;
        while(!q.empty()){
            Node* fn=q.front();
            if(fn->data==target){node=fn;check=false;}
            if(fn->left){
                m[fn->left]=fn;
                q.push(fn->left);
            }
            if(fn->right){
                m[fn->right]=fn;
                q.push(fn->right);
            }
            q.pop();
        }
        if(check)return 0;
        set<Node*> st;
        q.push(node);
        st.insert(node);
        int i=0;
        while(!q.empty()){
            int n=q.size();bool a=false;
            while(n){
            Node* fn =q.front();
            if(fn->left&&st.find(fn->left)==st.end()){
                st.insert(fn->left);
                a=true;
                q.push(fn->left);
            }
            if(fn->right&&st.find(fn->right)==st.end()){
                st.insert(fn->right);
                a=true;
                q.push(fn->right);
            }
            if(m.find(fn)!=m.end()&&st.find(m[fn])==st.end()){
                st.insert(m[fn]);
                a=true;
                q.push(m[fn]);
            }
            q.pop();
            n--;
            }
            if(a)i++;
        }
        return i;
        
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends