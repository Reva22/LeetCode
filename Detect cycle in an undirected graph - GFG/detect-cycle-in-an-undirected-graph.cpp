//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int i, vector<int>adj[], vector<int>&vis, int parent){
        
        vis[i]=1;
        
        for(int j=0;j<adj[i].size();j++){
            if(vis[adj[i][j]]==0 ){
                if (dfs(adj[i][j], adj, vis, i)) {
                    return true;
                }
            }
            else if (adj[i][j]!=parent){
                // cout<<i<<" Starting Node is"<<startingNode<<endl;
                return true;
            }
            // else if(i==startingNode){
            //     cout<<i<<" Starting Node is"<<startingNode<<endl;
            //     return true;
            // }
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++){
            if(vis[i]==0 && dfs(i,adj,vis,-1)==true){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends