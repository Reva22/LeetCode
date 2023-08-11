//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    
    int func(string &s, string &t, int i, int j, vector<vector<int>>& dp){
        int M = 1e9+7;
        if(i==-1 || j==-1){
            if(j==-1){
                return 1;
            }
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int take = 0, notake = 0;
        if(s[i]==t[j]){
            take = func(s,t,i-1,j-1,dp)%M;
        }
        notake = func(s,t,i-1,j,dp)%M;

        return dp[i][j] = (take+notake)%M;
    }

    int subsequenceCount(string s, string t)
    {
      //Your code here
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(s,t,n-1,m-1,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends