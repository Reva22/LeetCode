//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int i, vector<int>adj[], vector<int>&vis, vector<int>&ans){
        vis[i]=1;
        ans.push_back(i);
        for(int j=0;j<adj[i].size();j++){
            if(vis[adj[i][j]]==0){
             dfs(adj[i][j],adj,vis,ans);   
            }
        }
        return;
    }
    
    int numProvinces(vector<vector<int>> v, int V) {
        // code here
        vector<int>adj[V];
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<int>vis(V,0);
        vector<int>ans;
        
        int n = 0;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                n++;
                dfs(i,adj,vis,ans);
            }
        }
        
        return n;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends