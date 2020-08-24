class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int i,sz=intervals.size();
        vector<vector<int>>res;
        for(i=0;i<sz;i++)
        {
            if((intervals[i][1]<=toBeRemoved[0]) || (intervals[i][0]>=toBeRemoved[1]))
                res.push_back(intervals[i]);
            else if ((intervals[i][0]>=toBeRemoved[0]) && (intervals[i][1]<=toBeRemoved[1]))
                continue;
            else
            {
                if(intervals[i][0]<toBeRemoved[0])
                    res.push_back({intervals[i][0],toBeRemoved[0]});
                if(intervals[i][1]>toBeRemoved[1])
                    res.push_back({toBeRemoved[1],intervals[i][1]});
            }
        }
        return res;
    }
};
