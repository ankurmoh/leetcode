class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string,string>parent;
        unordered_set<string>s;
        int i,sz=regions.size(),j;
        for(i=0;i<sz;i++)
        {
            for(j=1;j<regions[i].size();j++)
            {
                parent[regions[i][j]]=regions[i][0];
            }
        }
        while(parent.find(region1) != parent.end())
        {
          s.insert(region1);
          region1=parent[region1];
        }
        s.insert(region1);
        while((s.find(region2) == s.end()) && (parent.find(region2) != parent.end()))
        {
            region2=parent[region2];
            if(s.find(region2) != s.end())
                break;
        }
        return region2;
    }
};
