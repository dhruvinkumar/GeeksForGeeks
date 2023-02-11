//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int countWords(string s[], int n)
        {
           //code here.
           map<string,int> m;
           for(int i=0;i<n;i++){
               m[s[i]]=0;
           }
           for(int i=0;i<n;i++){
               m[s[i]]++;
           }
           int count=0;
           
           map<string,int>::iterator it;
           for(it=m.begin();it!=m.end();it++){
               if(it->second==2)count++;
           }
           
           return count;
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
        string list[n];
        for(int i=0;i<n;i++)
            cin>>list[i];
        Solution ob;    
        cout <<ob.countWords(list, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends