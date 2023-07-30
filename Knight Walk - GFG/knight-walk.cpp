//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    KnightPos[0]--;
	    KnightPos[1]--;
	    TargetPos[0]--;
	    TargetPos[1]--;
	    
	    vector<vector<int>>dirs = {{-2,1},{-2,-1},{2,-1},{2,1},{1,2},{1,-2},{-1,2},{-1,-2}};
	    
	   // vector<vector<bool>> vis(N, vector<bool>(N, false));
	    
	    vector<vector<int>>dis(N,vector<int>(N,-1));
	    
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});
	    dis[KnightPos[0]][KnightPos[1]]=0;
	    
	    while(!q.empty()){
	        int x = q.front().first;
	        int y = q.front().second;
	        
	        q.pop();
	        
	       // vis[x][y]=true;
	        
	        if(x==TargetPos[0] && y==TargetPos[1]){
	           return dis[x][y];
	        }
	        
	        for(auto& it : dirs){
	            int nx = x + it[0];
	            int ny = y + it[1];
	            
	            if(nx>=0 && nx<N && ny>=0 && ny<N && dis[nx][ny]==-1){
	                dis[nx][ny] = 1 + dis[x][y];
	                q.push({nx,ny});
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
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends