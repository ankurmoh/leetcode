class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n=maze.size();
        if(n==0)
            return true;
        vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};

        int m=maze[0].size(),x,y,i,currentx,currenty;
        queue< pair<int,int> >q;
        q.push(make_pair(start[0],start[1]));
        vector<vector<int>>visited(n,vector<int>(m,0));
        visited[start[0]][start[1]]=1;
        while(!q.empty())
        {
            pair pp = q.front();
            q.pop();
            x=pp.first;
            y=pp.second;
            if((x==destination[0])&&(y==destination[1]))
                return true;
            for(i=0;i<4;i++)
            {
                currentx=x;
                currenty=y;
                while((currentx + dir[i][0]>=0)&&(currentx + dir[i][0]<n)&&(currenty + dir[i][1]>=0)&&(currenty + dir[i][1]<m)&&(maze[currentx+dir[i][0]][currenty+dir[i][1]]==0))
                {
                    currentx=currentx+dir[i][0];
                    currenty=currenty+dir[i][1];
                }

                if(visited[currentx][currenty]==1)
                    continue;
                else
                {
                    q.push(make_pair(currentx,currenty));
                    visited[currentx][currenty]=1;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
      queue< pair<int,int> >q;
      int n=maze.size();
        if(n==0)
            return -1;
        int m=maze[0].size(),x,y,currentx,currenty,count,i;
        vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
      q.push(make_pair(start[0],start[1]));
        vector <vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[start[0]][start[1]]=0;
        while(!q.empty())
        {
           pair<int,int> pp =q.front();
            q.pop();
            currentx=pp.first;
            currenty=pp.second;
            for(i=0;i<4;i++)
            {
                x=currentx;
                y=currenty;
                count=dist[currentx][currenty];
                while((x + dir[i][0] >=0)&&(x + dir[i][0] <n) && (y + dir[i][1]>=0) && (y + dir[i][1] <m)&&(maze[x+dir[i][0]][y+dir[i][1]]==0))
                {
                    x=x+dir[i][0];
                    y=y+dir[i][1];
                    count++;
                }
                if((dist[x][y]>count))
                {
                    dist[x][y]=count;
                    q.push(make_pair(x,y));
                }
            }
        }
        return (dist[destination[0]][destination[1]]==INT_MAX)? -1 : dist[destination[0]][destination[1]];
    }
};
