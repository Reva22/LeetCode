//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        vector<vector<int>>dirs = {{0,1},{0,-1},{-1,0},{1,0}};
        
        int n = grid.size();
        
        // map<pair<int,int>,int>vis;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         vis[{i,j}]=0;
        //     }
        // }
        
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        q.push({grid[0][0],{0,0}});
        dis[0][0]=grid[0][0];
        
        // queue<pair<int,int>>q;
        // q.push({0,0});
    
        
        while(!q.empty()){
            int x = q.top().second.first;
            int y = q.top().second.second;
            int price = q.top().first;
            
            q.pop();
            
            // vis[{x,y}]=1;
            
            if(x==n-1 && y==n-1){
                return price;
            }
            
            for(auto& it : dirs){
                int nx = x + it[0];
                int ny = y + it[1];
                
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    int temp = grid[nx][ny]+price;
                    if(temp<dis[nx][ny]){
                        dis[nx][ny]=temp;
                        q.push({grid[nx][ny]+price,{nx,ny}});
                    }
                    
                }
            }
        }
        
        return -1;
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends