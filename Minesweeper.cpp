class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};

    bool inside(int x,int y,vector<vector<char>>& board)
    {
         if((x<0)||(x>=board.size())||(y<0)||(y>=board[0].size()))
            return false;
        return true;
    }
    void reveal(vector<vector<char>>& board, int x,int y,vector<vector<int>>& visited)
    {
        if((x<0)||(x>=board.size())||(y<0)||(y>=board[0].size())||(visited[x][y]))
            return;
        int i,con=0,newx,newy;
        visited[x][y]=1;
        for(i=0;i<8;i++)
        {
            newx=x+dir[i][0];
            newy=y+dir[i][1];
            if(!inside(newx,newy,board))
                continue;
            if(board[newx][newy]=='M')
                con++;
        }
        if(con==0)
        {
            board[x][y]='B';
            for(i=0;i<8;i++)
            {
               newx=x+dir[i][0];
               newy=y+dir[i][1];
               reveal(board,newx,newy,visited);
            }
        }
        else if(con>0)
        {
            board[x][y]='0' + con;
            return;
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i,j,m=board.size(),n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        if(board[click[0]][click[1]]=='M')
        {
            board[click[0]][click[1]]='X';
            return board;
        }
        reveal(board,click[0],click[1],visited);
        return board;
    }
};
