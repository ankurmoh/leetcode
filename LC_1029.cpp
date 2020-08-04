class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
       int i,len=costs.size(),sum=0;
        vector<int>saving(len);
        for(i=0;i<len;i++)
        {
            sum=sum+costs[i][0];
            saving[i]=costs[i][1]-costs[i][0];
        }
        sort(saving.begin(),saving.end());
        for(i=0;i<saving.size()/2;i++)
            sum=sum+saving[i];
        return sum;
    }
};
