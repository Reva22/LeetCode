//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        vector<int>adj[n];
	    vector<int>tadj[n];
	    
	    for(int i=0;i<pre.size();i++){
	        adj[pre[i][0]].push_back(pre[i][1]);
	        tadj[pre[i][1]].push_back(pre[i][0]);
	    }
	    
	   // for(int i=0;i<n;i++){
	   //     for(int j=0;j<adj[i].size();j++){
	   //         cout<<adj[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    
	    vector<int>innodes(n,0);
	    queue<int>q;
	    
	    for(int i=0;i<n;i++){
	        innodes[i]=adj[i].size();
	        if(innodes[i]==0){
	            q.push(i);
	        }
	       // cout<<innodes[i]<<" ";
	    }
	   // cout<<endl;
	    
	    int c=0;
	    vector<int>ans,np;
	    
	    while(!q.empty()){
	        c++;
	        ans.push_back(q.front());
	        for(int i=0;i<tadj[q.front()].size();i++){
	            innodes[tadj[q.front()][i]]--;
	            if(innodes[tadj[q.front()][i]]==0){
	                q.push(tadj[q.front()][i]);
	            }
	        }
	        
	       // for(int i=0;i<n;i++){
	       //     cout<<innodes[i]<<" ";
	       // }
	       // cout<<endl;
	    
	        q.pop();
	    }
	    
	   // cout<<c<<endl;
	    if(c==n){
	        return ans;
	    }
	    
	    else{
	        return np;
	    }
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends