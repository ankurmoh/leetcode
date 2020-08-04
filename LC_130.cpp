class Solution {
public:
    void bfs(vector<vector<char>>& board,queue<pair<int,int>>& q)
    {
        pair<int,int>fron;
        int i,x1,y1;
        vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            fron=q.front();
            q.pop();
            for(i=0;i<4;i++)
            {
               x1=fron.first + dir[i][0];
               y1=fron.second + dir[i][1];
               if((x1>=0) && (x1<board.size()) && (y1>=0) && (y1<board[0].size()) && (board[x1][y1]=='O'))
               {
                   board[x1][y1]='B';
                   q.push(make_pair(x1,y1));
               }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int sz=board.size();
        if(sz==0)
            return ;
        int i,j,sz1=board[0].size();
        if(sz1==0)
            return;
        queue<pair<int,int>>q;
        for(i=0;i<sz;i++)
        {
            if(board[i][0]=='O')
            {
                q.push(make_pair(i,0));
                board[i][0]='B';
            }
             if(board[i][sz1-1]=='O')
             {
                 q.push(make_pair(i,sz1-1));
                 board[i][sz1-1]='B';
             }
        }
        for(i=0;i<sz1;i++)
        {
            if(board[0][i]=='O')
            {
                q.push(make_pair(0,i));
                board[0][i]='B';
            }
             if(board[sz-1][i]=='O')
             {
                 q.push(make_pair(sz-1,i));
                 board[sz-1][i]='B';
             }
        }
        bfs(board,q);
        for(i=0;i<sz;i++)
        {
            for(j=0;j<sz1;j++)
            {
                if(board[i][j]=='B')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
    }
};
