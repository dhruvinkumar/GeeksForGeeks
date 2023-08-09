int minJumps(int arr[], int n){
        // Your code here
        int count =0;
        for(int i=0;i<n-1;i++){
            int max=0;
            int ind=i;
            if(arr[i]+i>=n-1)return count+1;
            for(int j=i+1;j<=arr[i]+i;j++){
                if((arr[j]+j)>max){
                    max=arr[j]+j;
                    ind=j;
                }
            }
            if(max==0)return -1;
            i=ind-1;
            count++;
        }
        cout<<endl;
        return count;
    }