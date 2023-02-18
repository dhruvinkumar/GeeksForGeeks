//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& a, int n) {
       
        //code here   
        vector<long long> v;
        long long p = 1,d=0;
        for(int i=0;i<n;i++){
            if(a[i]!=0){
            p*=a[i];
            }else{
                d++;
            }
        }
        for(int i=0;i<n;i++){
          
          if(d>1){
              v.push_back(0);
          }else if(d==0){
              v.push_back(p/a[i]);
          }else{
              if(a[i]==0){
                  v.push_back(p);
              }else{
                  v.push_back(0);
              }
          }
          
          
        }
        return v;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends