//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int func(string a, string b, int i, int j, vector<vector<int>>& dp){
        if(i==-1 || j==-1){
            if(j==-1){
                return i;
            }
            return j;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(a[i]==b[j]){
            return dp[i][j]=func(a,b,i-1,j-1,dp);
        }

        int insert = 1 + func(a,b,i,j-1,dp);
        int replace = 1 + func(a,b,i-1,j-1,dp);
        int del = 1 + func(a,b,i-1,j,dp);

        return dp[i][j]=min({insert,replace,del});
    }

    int editDistance(string a, string b) {
        // Code here
        if(a==b) return 0;

        vector<vector<int>>dp(a.size(),vector<int>(b.size(),-1));

        return 1+func(a,b,a.size()-1,b.size()-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends