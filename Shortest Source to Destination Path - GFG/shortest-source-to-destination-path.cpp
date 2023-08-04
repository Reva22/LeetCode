//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> A, int X, int Y) {
        // code here
        
        vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        if(A[0][0]==0){
            return -1;
        }
        
        vector<vector<int>>dis(n,vector<int>(m,-1));
        dis[0][0]=0;
        
        queue<pair<int,int>>q;
        q.push({0,0});
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            
            if(x==X && y==Y){
                return dis[x][y];
            }
            
            for(auto &it : dirs){
                int nx = x + it[0];
                int ny = y + it[1];
                
                if(nx>=0 && nx<n && ny>=0 && ny<m && dis[nx][ny]==-1 && A[nx][ny]==1){
                    dis[nx][ny]=1+dis[x][y];
                    q.push({nx,ny});
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends