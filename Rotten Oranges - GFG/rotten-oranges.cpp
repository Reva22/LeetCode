//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>>q;
        map<pair<int,int>,int>vis;
        
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                vis.insert({{i,j},0});
            }
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    freshOranges++;
                }
            }
        }
        
        int minutes = -1;
        
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                int i = q.front().first;
                int j = q.front().second;
                
                if(i-1>=0 && grid[i-1][j]==1 && vis[{i-1,j}]==0){
                    freshOranges--;
                    vis[{i-1,j}]=1;
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                if(i+1<n && grid[i+1][j]==1 && vis[{i+1,j}]==0){
                    freshOranges--;
                    vis[{i+1,j}]=1;
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                if(j-1>=0 && grid[i][j-1]==1 && vis[{i,j-1}]==0){
                    freshOranges--;
                    vis[{i,j-1}]=1;
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                if(j+1<m && grid[i][j+1]==1 && vis[{i,j+1}]==0){
                    freshOranges--;
                    vis[{i,j+1}]=1;
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
                
                q.pop();
                size--;
            }
            minutes++;
        }
        
        if(freshOranges!=0){
            return -1;
        }
        
        return minutes;
        
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends