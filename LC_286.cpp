class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int i,j,sz=rooms.size(),x,y;
        vector <vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        if(sz==0)
            return;
        pair<int,int>fron;
        int sz1=rooms[0].size(),INF=INT_MAX;
        queue<pair<int,int>>q;
        for(i=0;i<sz;i++)
        {
            for(j=0;j<sz1;j++)
            {
                if(rooms[i][j]==0)
                    q.push(make_pair(i,j));
            }
        }
        while(!q.empty())
        {
            fron = q.front();
            q.pop();
            for(i=0;i<4;i++)
            {
                x=fron.first + dir[i][0];
                y=fron.second + dir[i][1];
                if((x<0) || (x>=sz) || (y<0) || (y>=sz1) || (rooms[x][y]!=INF))
                    continue;
                q.push(make_pair(x,y));
                rooms[x][y]=min(rooms[x][y],rooms[fron.first][fron.second]+1);
            }
        }
    }
};
