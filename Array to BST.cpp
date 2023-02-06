//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void make(vector<int> nums,vector<int>& v,int l,int r){
        if(l<=r){
             int n=(l+r)/2;
        v.push_back(nums[n]);
        make(nums,v,l,n-1);
        make(nums,v,n+1,r);
        }
        
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
       
        vector<int> v;
        make(nums,v,0,nums.size()-1);
        return v;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends