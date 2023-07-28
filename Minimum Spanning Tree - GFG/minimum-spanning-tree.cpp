//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>vis(n,0);
        pq.push({0,{0,-1}});
        
        int sum=0;
        
        while(!pq.empty()){
            
            int curNode = pq.top().second.first;
            int wt = pq.top().first;
            int fromNode = pq.top().second.second;
            if(vis[curNode]==0){
                sum+=wt;
                vis[curNode] = 1;
                
                pq.pop();
                
                for(auto it : adj[curNode]){
                    if(vis[it[0]]==0){
                        pq.push({it[1],{it[0],curNode}});
                    }
                }
            }
            else{
                pq.pop();
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends