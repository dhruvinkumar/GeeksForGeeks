//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int a[], int n) {
        // code here
        int b[n];
        for(int i=0;i<n;i++){
            b[i]=0;
        }
        for(int i=0;i<n;i++){
            b[a[i]]++;
        }
        vector<int> v;
        int d=0;
         for(int i=0;i<n;i++){
            if(b[i]>1){
                v.push_back(i);
                d++;
            }
        }
        if(d==0){
            v.push_back(-1);
        }
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends