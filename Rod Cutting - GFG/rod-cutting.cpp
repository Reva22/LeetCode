//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    vector<vector<int>>dp;
    int knapsack(int price[], int n, int i, int wt, vector<vector<int>>& dp){
        if(i==n || wt==0){
            return 0;
        }
        
        if(dp[i][wt]!=-1){
            return dp[i][wt];
        }
        
        int take = INT_MIN, notake = INT_MIN;
        if(wt-(i+1)>=0){
            take = price[i] + knapsack(price,n,i,wt-(i+1),dp);
        }
        notake = knapsack(price,n,i+1,wt,dp);
        
        return dp[i][wt] = max(take,notake);
    }
    
    int cutRod(int price[], int n) {
        //code here
        int maxSize = *max_element(price,price+n);
        maxSize*=n;
        dp.resize(1002,vector<int>(1002,-1));
        return knapsack(price,n,0,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends