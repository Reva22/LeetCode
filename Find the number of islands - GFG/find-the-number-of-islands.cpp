//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<int>adj[], int node, int vis[]){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(vis[it]!=1){
                dfs(adj,it,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = 0, sz = grid.size();
        map<pair<int,int>,int>mp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    mp[{i,j}] = n;
                    n++;
                }
            }
        }
        
        vector<int>adj[n];
        int st = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    if(i<sz && j+1<grid[i].size() && i>=0 && j+1>=0 && grid[i][j+1] == '1'){
                        adj[st].push_back(mp[{i,j+1}]);
                    }
                    if(i<sz && j-1<grid[i].size() && i>=0 && j-1>=0 && grid[i][j-1] == '1'){
                        adj[st].push_back(mp[{i,j-1}]);
                    }
                    if( i+1<sz && j<grid[i].size() && i+1>=0 && j>=0 && grid[i+1][j] == '1'){
                        adj[st].push_back(mp[{i+1,j}]);
                    }
                    if( i-1<sz && j<grid[i].size() && i-1>=0 && j>=0 && grid[i-1][j] == '1' ){
                        adj[st].push_back(mp[{i-1,j}]);
                    }
                    if(i+1<sz && j+1<grid[i].size() && i+1>=0 && j+1>=0  && grid[i+1][j+1] == '1'){
                        adj[st].push_back(mp[{i+1,j+1}]);
                    }
                    if(i-1<sz && j-1<grid[i].size() && i-1>=0 && j-1>=0 && grid[i-1][j-1] == '1'){
                        adj[st].push_back(mp[{i-1,j-1}]);
                    }
                    if(i+1<sz && j-1<grid[i].size() && i+1>=0 && j-1>=0 && grid[i+1][j-1] == '1' ){
                        adj[st].push_back(mp[{i+1,j-1}]);
                    }
                    if(i-1<sz && j+1<grid[i].size() && i-1>=0 && j+1>=0 &&grid[i-1][j+1] == '1'){
                        adj[st].push_back(mp[{i-1,j+1}]);
                    }
                    st++;
                }
            }
        }
        
        int vis[n];
        for(int i=0;i<n;i++){vis[i]=0;}
        int count = 0;
        
        
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                dfs(adj,i,vis);
                count++;
            }
        }
        
        return count;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends