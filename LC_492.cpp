class Solution {
public:
    vector<int> constructRectangle(int area) {
        int length=area,width=1,mindiff=INT_MAX,reslen,reswid;
        while(length>=width)
        {
           if((mindiff>(length-width)) && (length*width == area))
           {
               mindiff=length-width;
               reslen=length;
               reswid=width;
           }
           width=width+1;
           length=area/width;
           if(length<width)
               break;
        }
        vector<int>res;
        res.push_back(reslen);
        res.push_back(reswid);
        return res;
    }
};
