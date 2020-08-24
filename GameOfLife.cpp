class Solution {
public:
    bool valid(int x,int y,vector<vector<int>>& board)
    {
        int n=board.size(),m=board[0].size();
        if((x>=0)&&(x<n)&&(y>=0)&&(y<m)&&(board[x][y]&1))
            return true;
        return false;
    }
    void gameOfLife(vector<vector<int>>& board)
    {
        vector<vector<int>>moves = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
        int n=board.size();
        if(n==0)
            return;
        int i,j,x,y,m=board[0].size(),lives,k;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                lives=0;
                for(k=0;k<8;k++)
                {
                    x=i+moves[k][0];
                    y=j+moves[k][1];
                    if(valid(x,y,board))
                        lives++;
                }
                if(board[i][j]&1)
                {
                    if((lives>=2)&&(lives<=3))
                        board[i][j]=3;
                }
                else
                {
                    if(lives==3)
                        board[i][j]=2;
                }
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                board[i][j]/=2;
    }
};
