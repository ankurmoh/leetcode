class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        int i,sz=intervals.size(),prev=0,min1,max1;
        if(sz==0)
            return res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(i=1;i<sz;i++)
        {
            vector<int>v=intervals[i];
            if(v[0]>res[prev][1])
            {
                res.push_back(v);
                prev++;
            }
            else if(v[0]<=res[prev][1])
            {
                min1=res[prev][0];
                max1=max(res[prev][1],v[1]);
                res.pop_back();
                vector<int>v1={min1,max1};
                res.push_back(v1);
            }
        }
        return res;
    }
};
