//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<long long int>>dp;
    int func(int n, vector<int>& prices, int i, bool canBuy){
        if(i==n){
            return 0;
        }
        
        if(dp[i][canBuy]!=-1){
            return dp[i][canBuy];
        }
        
        int buy = 0, sell = 0;
        int skip = func(n,prices,i+1,canBuy);
        if(canBuy==true){
            canBuy=false;
             buy = func(n,prices,i+1,canBuy) - prices[i];
        }
        else{
            canBuy=true;
             sell = func(n,prices,i+1,canBuy) + prices[i];
        }
        
        return dp[i][!canBuy] = max({buy,sell,skip});
    }
  
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
         int profit =0;
        for (int i=1; i<n; i++){
            profit+= max(0, prices[i]-prices[i-1]);
        }
        return profit;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends