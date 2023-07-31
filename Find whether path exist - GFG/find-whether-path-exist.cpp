//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        
        queue<pair<int,int>>q;
        
        vector<vector<int>>vis(grid.size(),vector<int>(grid.size(),0));
        
        int tx,ty;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            
            vis[x][y]=1;
            
            q.pop();
            
            for(auto& it: dirs){
                int nx = x + it[0];
                int ny = y + it[1];
                
                if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid.size() && vis[nx][ny]==0){
                    if(grid[nx][ny]==3){
                        q.push({nx,ny});
                    }
                    else if (grid[nx][ny] == 2){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends