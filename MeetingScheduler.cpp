class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(),slots1.end(),[](const vector<int>& v1,const vector<int>& v2)
             { return (v1[0]<v2[0]); });
        sort(slots2.begin(),slots2.end(),[](const vector<int>& v1,const vector<int>& v2)
             { return (v1[0]<v2[0]); });
        int i=0,sz1=slots1.size(),j=0,sz2=slots2.size(),mindur,maxdur;
        vector<int>res;
        if((sz1==0) || (sz2==0))
            return res;
        while((i<sz1) && (j<sz2))
        {
            mindur = max(slots1[i][0],slots2[j][0]);
            maxdur = min(slots1[i][1],slots2[j][1]);
            if(mindur + duration <= maxdur)
            {
                res = {mindur,mindur+duration};
                return res;
            }
            else if(slots1[i][1]<slots2[j][1])
                i++;
            else
                j++;
        }
        return res;
    }
};
