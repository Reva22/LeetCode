//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int l=0;
    int r=n-1;
    int temp=-1;
    vector<int>ans(2,-1);
   
    while(l<=r){
        int m = (l+r)/2;
        if(arr[m]==x){
            temp = m;
            r = m-1;
        }
        else if (arr[m]<x){
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    
    // cout<<temp<<endl;
    ans[0]=temp;
    
    l=0;
    r=n-1;
    
    while(l<=r){
        int m = (l+r)/2;
        if(arr[m]==x){
            temp = m;
            l = m+1;
        }
        else if (arr[m]<x){
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    // cout<<temp<<endl;
    ans[1]=temp;
    
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends