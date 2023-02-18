//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
       vector<vector<int>> v1;
       if(n==0)return v1;
       int level=1,i=0;
       while(i<n){
           vector<int> v;
           while(i<level&&i<n){
               v.push_back(arr[i]);
               i++;
           }
           sort(v.begin(),v.end());
           v1.push_back(v);
           v.clear();
           level=level*2+1;
       }
       return v1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

        Solution ob;
        
		vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends