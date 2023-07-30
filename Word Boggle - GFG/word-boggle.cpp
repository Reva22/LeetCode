//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
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
        vector<vector<int>> dirs = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
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
    
    bool boss(vector<vector<char>>&board, string s){
        
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
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<string>res;
	    for(int i=0;i<dictionary.size();i++){
	        if(boss(board,dictionary[i])){
	            res.push_back(dictionary[i]);
	        }
	    }
	    
	    return res;
	}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends