class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        int i,sz=points.size(),j,res=0,x,y;
        vector<int>point1;
        vector<int>point2;
        for(i=0;i<sz;i++)
        {
            point1=points[i];
            mp.clear();
            for(j=0;j<sz;j++)
            {
                if(j==i)
                    continue;
                point2=points[j];
                x=point2[0]-point1[0];
                y=point2[1]-point1[1];
                mp[x*x + y*y] += 1;
            }
            for(auto it=mp.begin();it!=mp.end();it++)
                res = res + (it->second)*(it->second - 1);
        }
        return res;
    }
};
