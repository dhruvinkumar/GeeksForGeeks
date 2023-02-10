//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        int n=s.length();
        map<char,int>  m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        
        
        int x=min(m['b'],min(m['a'],m['n']));
        int y=min(m['l'],m['o']);
        if(x<y){
            if(x==0)return 0;
            if(y%x==0)return x;
            else return y/2;
        }
        return y/2;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends