//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[n];
        vector<pair<int,int>>tadj[n];
        
       
        for(int i=0;i<m;i++){
            adj[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
            tadj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        }
        
        vector<int>innodes(n,0);
        queue<int>q;
        
        for(int i=0;i<n;i++){
	        innodes[i]=adj[i].size();
	        if(innodes[i]==0){
	            q.push(i);
	        }
	    }
        
        int c=0;
        vector<int>res;
	    
	    while(!q.empty()){
	        c++;
	        res.push_back(q.front());
	        
	        for(int i=0;i<tadj[q.front()].size();i++){
	            innodes[tadj[q.front()][i].first]--;
	            if(innodes[tadj[q.front()][i].first]==0){
	                q.push(tadj[q.front()][i].first);
	            }
	        }
	    
	        q.pop();
	    }
	    
	    vector<int>ds(n);
	    for(int i=0;i<n;i++){ds[i]=1e9;}
	    ds[0]=0;
	    
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends