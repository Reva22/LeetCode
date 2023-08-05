//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<int,int>>& q){
        vector<vector<int>>dirs={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            
            if(vis[x][y]==1){
                q.pop();
            }
            
            else{
                ans++;
                vis[x][y]=1;
                
                q.pop();
                
                for(auto &it : dirs){
                    int nx = x + it[0];
                    int ny = y + it[1];
                    
                    if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0 && grid[nx][ny]==1){
                        q.push({nx,ny});
                    }
                }
            }
            
        }
        
        return ans;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<int,int>>q;
        
        int res = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    q.push({i,j});
                    res = max(res, bfs(grid,vis,q));
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends