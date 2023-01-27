//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string a;
        string b;
        for(int i=0;i<str.length();i++){
            if(isupper(str[i]))a+=str[i];
            if(islower(str[i]))b+=str[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        // cout<<a<<" "<<b<<endl;
        
        int l=0,k=0;
        
        for(int i=0;i<n;i++){
            if(isupper(str[i])){str[i]=a[k];k++;}
            if(islower(str[i])){str[i]=b[l];l++;}
        }
        return str;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends