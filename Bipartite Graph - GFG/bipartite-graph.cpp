//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int st, vector<int>adj[], vector<int>& vis, int color, map<int,int>&mp){
        vis[st]=1;
        mp[st]=color;
        
        for(int i=0;i<adj[st].size();i++){
            if(vis[adj[st][i]]==0){
                if (dfs(adj[st][i],adj,vis,1-color,mp)==false){
                    return false;
                }
            }
            else if(color==mp[adj[st][i]]){
               return false;
            }
        }
        return true;
    }
    
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int>vis(n,0);
	    map<int,int>mp;
        
        for(int i=0;i<n;i++){
            if(vis[i]==0 && dfs(i,adj,vis,1,mp)==false){
                return false;
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends