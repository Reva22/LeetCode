//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        // vector<int>ans(n,0);
        // for(int i=0;i<n;i++){
        //     ans[i]=1e9;
        // }
        // ans[src]=0;
        
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        // minHeap.push(make_pair(src,0));
        
        // vector<int>vis(n,0);
        
        // while(!minHeap.empty()){
            
        //     int temp = minHeap.top().first;
            
        //     if(vis[temp]==0){
                
        //         for(auto it:adj[temp]){
                    
        //             int v = it[0];
        //             int wt = it[1];
                    
        //             if(ans[temp]+wt<ans[v]){
        //                 ans[v]=ans[temp]+wt;
        //                 minHeap.push(make_pair(v,ans[v]));
        //             }
        //         }
                
        //         minHeap.pop();
        //     }
        //     else{
        //         minHeap.pop();
        //     }
        // }
        
        // for(int i=0;i<ans.size();i++){
        //     if(vis[i]==0){
        //         for(auto it:adj[i]){
                    
        //             int v = it[0];
        //             int wt = it[1];
                    
        //             if(ans[i]+wt<ans[v]){
        //                 ans[v]=ans[i]+wt;
        //             }
        //         }
        //     }
        //     if(vis[i]==1e9){
        //         ans[i]=-1;
        //     }
        // }
        
        // return ans;
        
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V,INT_MAX);
        dist[S]=0;
        vector<bool>visited(V,false);
        pq.push({0,S});
        while(pq.empty()==false){
            if(visited[pq.top().second]==false){
                int u=pq.top().second;
                int wt=pq.top().first;
                pq.pop();
                for(auto v:adj[u]){
                    if(dist[v[0]]>wt+v[1]){
                        dist[v[0]]=wt+v[1];
                        pq.push({dist[v[0]],v[0]});
                    }
                }
            }
            else{
                pq.pop();
            }
        }
        return dist;
       
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