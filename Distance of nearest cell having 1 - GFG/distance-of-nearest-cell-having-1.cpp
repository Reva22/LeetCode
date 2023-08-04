//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
	    
	    int n = grid.size(), m = grid[0].size();
	    
	    vector<vector<int>>dis(n,vector<int>(m,-1));
        
         queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            
            for(auto &it : dirs){
                int nx = x + it[0];
                int ny = y + it[1];
                
                if(nx>=0 && nx<n && ny>=0 && ny<m && dis[nx][ny]==-1 && grid[nx][ny]==0){
                    dis[nx][ny]=1+dis[x][y];
                    q.push({nx,ny});
                }
            }
        }
        
        return dis;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends