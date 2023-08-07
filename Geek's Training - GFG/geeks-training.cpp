//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int func(vector<vector<int>>& points, int n, vector<vector<int>>&dp,int st,int i){
        vector<int>dirs = {0,1,2};
        if(st==n){
            return 0;
        }
        // if(st==n-1){
        //     dp[st][i]=points[st][i];
        // }
        
        if(dp[st][i]==-1){
            for(auto it:dirs){
                if(i!=it){
                    dp[st][i]=max(dp[st][i], points[st][i]+func(points,n,dp,st+1,it));
                }
            }
        }
        
        return dp[st][i];
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        int ans=0;
        
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        
        ans = max({func(points,n,dp,0,0),func(points,n,dp,0,1),func(points,n,dp,0,2)});
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends