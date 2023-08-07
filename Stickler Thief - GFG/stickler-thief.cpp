//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int func(vector<int>& dp, int arr[], int n, int st){
        if(st>n-1){
            return 0;
        }
        if(st==n-1 || st==n-2){
            dp[st]=arr[st];
        }
        
        if(dp[st]==-1){
            dp[st]=arr[st]+max(func(dp, arr, n, st+2),func(dp, arr, n, st+3));
        }
        
        return dp[st];
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n,-1);
        int maxi = max(func(dp,arr,n,0),func(dp,arr,n,1));
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends