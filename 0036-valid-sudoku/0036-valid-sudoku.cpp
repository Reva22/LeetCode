class Solution {
public:

    bool check( int i, int j, vector<vector<char>>& board, int (&vis)[9][9]){
        vis[i][j]=1;
        int c =0;
        for(int x=0;x<9;x++){
            if(board[i][j]==board[i][x]){c++;}
            if(c>1){
                return false;
            }
        }
        c=0;
        for(int x=0;x<9;x++){
            if(board[i][j]==board[x][j]){c++;}
            if(c>1){
                return false;
            }
        }
        c=0;
        int a = i/3;
        int b = j/3;
        for(int x=0+3*a;x<3+3*a;x++){
            for(int y=0+3*b;y<3+3*b;y++){
               if(board[i][j]==board[x][y]) {
                   c++;
               }
                if(c>1){
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int c=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    c++;
                }
            }
        }

        int vis[9][9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    vis[i][j]=0;
                }
            }
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && vis[i][j]==0){
                    if(check(i,j,board,vis)==false){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};