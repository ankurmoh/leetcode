class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>>graph;
        int i,sz=roads.size(),j,maxi=0,sum;
        for(i=0;i<sz;i++)
        {
            graph[roads[i][0]].insert(roads[i][1]);
            graph[roads[i][1]].insert(roads[i][0]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                sum = graph[i].size() + graph[j].size();
                if(graph[i].count(j))
                {
                    sum=sum-1;
                }
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};
