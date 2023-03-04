//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    set<char> m;
    for(int i=0;i<s.length();i++){
        if(m.find(s[i])!=m.end()){
            string b(1, s[i]);
            return b;
        }
        m.insert(s[i]);
    }
    return "-1";
}