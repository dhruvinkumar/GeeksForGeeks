//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> a, int m, int n){
        //code here
        int k=1,i=0,j=0;
        pair<int,int>p;
        while(i>=0&&i<m&&j>=0&&j<n){
          p={i,j};
        //   cout<<"("<<p.first<<","<<p.second<<")"<<" ";
            if(a[i][j]==1){
                k++;
                a[i][j]=0;
            }
            if(k%4==1){
                j++;
            }else if(k%4==2){
               i++;
            }else if(k%4==3){
                j--;
                }else if(k%4==0){
               i--;
            }
              
        }
        return p;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends