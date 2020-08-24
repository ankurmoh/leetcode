class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
     int i,j,diag=0,anti=0,flagA=0,flagB=0,x=0,o=0;
    vector<int>row(3,0);
        vector<int>col(3,0);
     for(i=0;i<3;i++)
     {
         for(j=0;j<3;j++)
         {
             if(board[i][j]=='X')
             {
                 x++;
                 row[i]++;
                 col[j]++;
                 if(i==j)
                     diag++;
                 if(i+j==2)
                     anti++;
             }
             else if(board[i][j]=='O')
             {
                 o++;
                 row[i]--;
                 col[j]--;
                 if(i==j)
                     diag--;
                 if(i+j==2)
                     anti--;
             }
         }
     }
        if((row[0]==3)||(row[1]==3)||(row[2]==3)||(col[0]==3)||(col[1]==3)||(col[2]==3)||(diag==3)||(anti==3))
            flagA=1;
        if((row[0]==-3)||(row[1]==-3)||(row[2]==-3)||(col[0]==-3)||(col[1]==-3)||(col[2]==-3)||(diag==-3)||(anti==-3))
            flagB=1;
        if(o>x)
            return false;
        if(x>=o+2)
            return false;
        if(flagA && flagB)
            return false;
        if((flagA) && (x==o))
            return false;
        if((flagB)&&(x!=o))
            return false;
        return true;
    }
};
