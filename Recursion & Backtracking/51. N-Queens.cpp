


class Solution {
public:
    bool isSafe(int x, int y,vector<string>&board,int n ){
        int row=x, col=y;
        while(row>=0 && col>=0){
             if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row=x,col=y;
         while(row<n && col>=0){
             if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        row=x,col=y;
        while(col>=0){
             if(board[row][col]=='Q')
                return false;
            col--;
        }
        
        return true;
        
    }
    void solve(int col, vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<vector<string>>ans;
        //unordered_map<int,int>left,lower,upper;
        solve(0,board,ans,n);
        return ans;
    }
};
