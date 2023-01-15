//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool ispalindrom(string s){
      int n = s.length();
      for(int i=0;i<=n/2;i++){
          if(s[i]!=s[n-i-1]){
              return false;
          }
      }
      return true;
  }
    
    string longestPalin (string s) {
        // code here
        int n = s.length();
        string d="";
        for(int i=0;i<n;i++){
            string c="";
            for(int j=i;j<n;j++){
                c+=s[j];
            if(d.length()<c.length()){
                if(ispalindrom(c)){
                d=c;
                }
            }
            }
            c.clear();
        }
        return d;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
