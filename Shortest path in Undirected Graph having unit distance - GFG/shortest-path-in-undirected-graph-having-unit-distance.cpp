//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        vector<pair<int,int>>adj[n];
       
        for(int i=0;i<m;i++){
            adj[edges[i][1]].push_back(make_pair(edges[i][0],1));
            adj[edges[i][0]].push_back(make_pair(edges[i][1],1));
        }
	    
	    queue<int>q;
	    q.push(src);
	    
	    vector<int>res;
	    vector<int>vis(n,0);
	    
	   // for(int i=0;i<n;i++){
    //         for(int j=0;j<adj[i].size();j++){
    //             cout<<adj[i][j].first<<" ";
    //         }
    //         cout<<endl;
    //     }
        
	    
	    while(!q.empty()){
	        if(vis[q.front()]==0){
	            vis[q.front()]=1;
    	        res.push_back(q.front());
    	        for(int i=0;i<adj[q.front()].size();i++){
    	            if(vis[adj[q.front()][i].first] == 0){
    	                q.push(adj[q.front()][i].first);
    	            }
    	        }
	        }
	        q.pop();
	    }
	    
	   // for(int i=0;i<res.size();i++){
	   //     cout<<res[i]<<" ";
	   // }
	   // cout<<endl;
	    
	    vector<int>ds(n);
	    for(int i=0;i<n;i++){ds[i]=1e9;}
	    ds[src]=0;
	    
	    for(int i=0;i<res.size();i++){
	        for(auto it:adj[res[i]]){
	            
	            int v = it.first;
	            int wt = it.second;
	            
	            ds[res[i]] = min(ds[res[i]],ds[v]+wt);
	            
	        }
	    }
	    for(int i=0;i<n;i++){
	        if(ds[i]==1e9){
	            ds[i]=-1;
	        }
	    }
	    
	    return ds;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends