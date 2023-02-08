//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int gcd(int a, int b)
{
    if (a == 0)   return b;
        gcd(b % a, a);
}
    int maxBinTreeGCD(vector<vector<int>> v, int N) {
        // code here
        if(v.size()==0)return 0;
        int maxi=0;
        sort(v.begin(), v.end());
        for(int i=0;i<v.size()-1;i++){
            int a=INT_MIN;
            if(v[i][0]==v[i+1][0]){
             a=gcd(v[i][1],v[i+1][1]);
            }
            if(a>maxi){
                maxi=a;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends