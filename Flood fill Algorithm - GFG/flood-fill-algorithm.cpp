//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<int>adj[], int node, int vis[]){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(vis[it]!=1){
                dfs(adj,it,vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        // Code here 
        int n = 0, sz = grid.size();
        map<pair<int,int>,int>mp;
        map<int,pair<int,int>>pm;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==grid[sr][sc]){
                    mp[{i,j}] = n;
                    pm[n] = {i,j};
                    n++;
                }
            }
        }
        
        vector<int>adj[n];
        int st = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==grid[sr][sc]){
                    if(i<sz && j+1<grid[i].size() && i>=0 && j+1>=0 && grid[i][j+1] == grid[sr][sc]){
                        adj[st].push_back(mp[{i,j+1}]);
                    }
                    if(i<sz && j-1<grid[i].size() && i>=0 && j-1>=0 && grid[i][j-1] == grid[sr][sc]){
                        adj[st].push_back(mp[{i,j-1}]);
                    }
                    if( i+1<sz && j<grid[i].size() && i+1>=0 && j>=0 && grid[i+1][j] == grid[sr][sc]){
                        adj[st].push_back(mp[{i+1,j}]);
                    }
                    if( i-1<sz && j<grid[i].size() && i-1>=0 && j>=0 && grid[i-1][j] == grid[sr][sc] ){
                        adj[st].push_back(mp[{i-1,j}]);
                    }
                    st++;
                }
            }
        }
        
        int vis[n];
        for(int i=0;i<n;i++){vis[i]=0;}
        int count = 0;
        
        
        dfs(adj,mp[{sr,sc}],vis);
        
        for(int i=0;i<n;i++){
            
            if(vis[i]==1){
                int x = pm[i].first;
                int y = pm[i].second;
                
                grid[x][y] = newColor;
            }
            
        }
        
        
        return grid;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends