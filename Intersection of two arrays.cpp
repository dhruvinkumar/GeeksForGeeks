//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        if(n==0||m==0)return 0;
        if(n<m){
            set<int> s1;
            set<int> cnt;
            for(int i=0;i<n;i++){
                s1.insert(a[i]);
            }
            for(int i=0;i<m;i++){
                if(s1.find(b[i])!=s1.end())cnt.insert(b[i]);
            }
            return cnt.size();
        }else{
             set<int> s1;
            set<int> cnt;
            for(int i=0;i<m;i++){
                s1.insert(b[i]);
            }
            for(int i=0;i<n;i++){
                if(s1.find(a[i])!=s1.end())cnt.insert(a[i]);
            }
            return cnt.size();
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends