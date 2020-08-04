class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int sz=points.size(),i,j,minarea=INT_MAX,dim1,dim2;
        unordered_map< int, set<int> >mp;

        for(i=0;i<sz;i++)
            mp[points[i][0]].insert(points[i][1]);

        for(i=0;i<sz;i++)
        {
            for(j=i+1;j<sz;j++)
            {
                if((points[i][0]==points[j][0]) || (points[i][1]==points[j][1]))
                    continue;
                if((mp[points[i][0]].count(points[j][1])) && (mp[points[j][0]].count(points[i][1])))
                {
                    dim1 = abs(points[j][0]-points[i][0]);
                    dim2 = abs(points[j][1]-points[i][1]);
                    minarea=min(minarea, dim1*dim2);
                }
            }
        }
        return minarea==INT_MAX ? 0: minarea;
    }
};
