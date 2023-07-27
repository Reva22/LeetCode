//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        // Code here
       vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=1e9;
        }
        ans[src]=0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push(make_pair(src,0));
        
        
        while(!minHeap.empty()){
            
            int temp = minHeap.top().first;
            minHeap.pop();
            
            for(auto it:adj[temp]){
                
                int v = it[0];
                int wt = it[1];
                
                if(ans[temp]+wt<ans[v]){
                    ans[v]=ans[temp]+wt;
                    minHeap.push(make_pair(v,ans[v]));
                }
            }
            
        }
        
        return ans;
       
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends