//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	int bs(int a[],int l,int r,int k){
	    if(l>r)return -1;
	    int mid=(l+r)/2;
	    if(a[mid]==k)return mid;
	    else if(a[mid]<k)return bs(a,mid+1,r,k);
	    else if(a[mid]>k)return bs(a,l,mid-1,k);
	}
	
	void convert(int arr[], int n) {
	    // code here
	   // if(n==1)arr[0]=0;
	    int b[n];
	    for(int i=0;i<n;i++){
	        b[i]=arr[i];
	    }
	    sort(b,b+n);
	    for(int i=0;i<n;i++){
	        arr[i]=bs(b,0,n-1,arr[i]);
	    }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends