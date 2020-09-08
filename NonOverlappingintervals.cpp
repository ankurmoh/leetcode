class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i,sz=intervals.size(),prev=0,con=0;
        if(sz<=1)
            return 0;
        for(i=1;i<sz;i++)
        {
            vector<int>cur=intervals[i];
            if(cur[0]>=intervals[prev][1])
                prev=i;
            else if(cur[0]<intervals[prev][1])
            {
                con++;
                if(intervals[prev][1]>cur[1])
                    prev= i;
            }
        }
        return con;
    }
};
