//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int bs(int a[],int l,int  r,int k){
      if(l<=r){
      int mid=(l+r)/2;
      if(a[mid]==k){
          return mid;
      }else if(k<a[mid]){
        bs(a,l,mid-1,k);
      }else{
          bs(a,mid+1,r,k);
      }
      }else{
      return -1;
      }
  }
    int binarysearch(int arr[], int n, int k) {
        // code here
        
        return bs(arr,0,n-1,k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends