//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    Node* find(Node* root,int k){
        if(root==NULL)return NULL;
        if(root->data==k)return root;
        Node* l=find(root->left,k);
        Node* r=find(root->right,k);
        if(l)return l;
        if(r)return r;
        return NULL;
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int> v;
        Node* node=find(root,target);
        
        if(node==NULL)return v;
        
        map<Node*,Node*> m;
        queue<Node*> q;
        q.push(root);
        m[root]=NULL;
        while(!q.empty()){
           Node* n=q.front();
           if(n->left)q.push(n->left);m[n->left]=n;
           if(n->right)q.push(n->right);m[n->right]=n;
           q.pop();
        }
        
        set<Node*> s;
        int i=0;
        q.push(node);
        s.insert(node);
        while(i!=k&&!q.empty()){
            int n=q.size();
            while(n--){
                s.insert(q.front());
                if(q.front()->left&&s.find(q.front()->left)==s.end()){
                    q.push(q.front()->left);
                }
                if(q.front()->right&&s.find(q.front()->right)==s.end()){
                    q.push(q.front()->right);
                }
                if(m[q.front()]&&s.find(m[q.front()])==s.end()){
                    q.push(m[q.front()]);
                }
                q.pop();
            }
            i++;
        }
        
        while(!q.empty()){
            v.push_back(q.front()->data);
            q.pop();
        }
        
        sort(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends