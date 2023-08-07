//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&knight,vector<int>&target,int n)
	{
	    // Code here
	    vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, -1));
    
        knight[0]--; // Convert to 0-based index
        knight[1]--; // Convert to 0-based index
        target[0]--; // Convert to 0-based index
        target[1]--; // Convert to 0-based index
    
        q.push({knight[0], knight[1]});
        dist[knight[0]][knight[1]] = 0;
    
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
    
            if (x == target[0] && y == target[1]) {
                return dist[x][y];
            }
    
            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
    
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
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