class Solution {
public:
    int difference(string& f1,string& f2)
    {
        int h1=stoi(f1.substr(0,2)), h2=stoi(f2.substr(0,2)), m1=stoi(f1.substr(3,2)), m2=stoi(f2.substr(3,2));
        int diff = abs(h1*60 + m1 - h2*60 - m2);
        return diff;
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int i,sz=timePoints.size(),diff,mini=9999999;
        for(i=0;i<sz;i++)
        {
            diff = difference(timePoints[(i+1) % sz],timePoints[i]);
            diff = min(diff,24*60 - diff);
            mini=min(mini,diff);
        }
        return mini;
    }
};
