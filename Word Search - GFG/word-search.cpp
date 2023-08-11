//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     
    void clear(vector<pair<int,int>>&store, vector<vector<int>>&vis, int n){
        for(int i=n;i<store.size();i++){
            vis[store[i].first][store[i].second]=0;
        }
        auto it = store.begin()+n;
        store.erase(it,store.end());
    }

    bool particular(stack<pair<int, pair<int, int>>>& q, vector<vector<char>>& board, string s) {
        vector<vector<int>> dirs = { {-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        vector<int>keeptrack;
        vector<pair<int,int>>store;
        keeptrack.push_back(0);
        while (!q.empty()) {
            int i = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            
            if(i<keeptrack[keeptrack.size()-1]){
                clear(store,vis,i);
            }
            
            i++;
            keeptrack.push_back(i);
            store.push_back({x,y});
            
            vis[x][y] = 1;
            
            q.pop();
            
            if (i == s.size()) {
                return true;
            }
            
            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && vis[nx][ny] == 0) {
                    if (board[nx][ny] == s[i]) {
                        q.push({ i, {nx, ny} });
                    }
                }
            }
        }
                
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string s) {
        // Code here
        stack<pair<int,pair<int,int>>>q;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==s[0]){
                    q.push({0,{i,j}});
                }
            }
        }
        
        if(particular(q,board,s)){
            return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends