class Solution {
public:
    bool isPathCrossing(string path) {
        int i, len=path.length(), x=0, y=0;
        map<pair<int,int>, int>mp;
        mp[make_pair(0,0)]=1;
        for(i=0;i<len;i++)
        {
            if(path[i]=='N')
                y=y+1;
            else if(path[i]=='S')
                y=y-1;
            else if(path[i]=='E')
                x=x+1;
            else
                x=x-1;
            if(mp.find(make_pair(x,y))!=mp.end())
                return true;
            mp[make_pair(x,y)]=1;
        }
        return false;
    }
};
