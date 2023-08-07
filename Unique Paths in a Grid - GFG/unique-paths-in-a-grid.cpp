//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    const int mod=1e9+7;
    int func(vector<vector<int>> &grid,vector<vector<int>> &dp, int i, int j){
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(i>=n or j>=m or grid[i][j]==0){
            return 0;
        }
        
        if(i==n-1 && j==m-1){
            if(grid[i][j])
            return 1;
            return 0;
        }
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int ans=(func(grid,dp,i+1,j)%mod+func(grid,dp,i,j+1)%mod)%mod;
       
        
        return dp[i][j]=ans%mod;
    }
  
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return func(grid,dp,0,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends