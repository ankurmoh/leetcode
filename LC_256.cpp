class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int i,sz=costs.size();
        if(sz==0)
            return 0;
        vector<int>red(sz+1,0);
        vector<int>blue(sz+1,0);
        vector<int>green(sz+1,0);
        red[0]=costs[0][0];
        blue[0]=costs[0][1];
        green[0]=costs[0][2];
        for(i=1;i<sz;i++)
        {
            red[i]=costs[i][0]+ min(blue[i-1],green[i-1]);
            blue[i]=costs[i][1] + min(red[i-1],green[i-1]);
            green[i]=costs[i][2] + min(blue[i-1],red[i-1]);
        }
        return min(red[sz-1], min(blue[sz-1],green[sz-1]));
    }
};
