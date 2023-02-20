

/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

/* The function should print all the paths from root
 to leaf nodes of the binary tree */
 void pre(Node* root,vector<int> v,vector<vector<int>>& v1){
     if(root==NULL)return ;
     if(!root->left&&!root->right){
         v.push_back(root->data);
         v1.push_back(v);
         return ;
     }
     v.push_back(root->data);
     pre(root->left,v,v1);
     pre(root->right,v,v1);
     
 }
 
 
vector<vector<int>> Paths(Node* root)
{
    // Code here
 vector<vector<int>> v1;
    vector<int> v;
    pre(root,v,v1);
    return v1;
}