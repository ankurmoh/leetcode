class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i,len=seats.size(),mini,maxi=INT_MIN,res;
        vector<int>left(len,len);
        vector<int>right(len,len);
        for(i=0;i<len;i++)
        {
            if(seats[i]==1)
                left[i]=0;
            else if(i>0)
                left[i]=left[i-1]+1;
        }
        for(i=len-1;i>=0;i--)
        {
            if(seats[i]==1)
                right[i]=0;
            else if(i<len-1)
                right[i]=right[i+1]+1;
        }
        for(i=0;i<len;i++)
        {
            if (seats[i]==0)
            {
            mini=min(left[i],right[i]);
            maxi=max(maxi,mini);
            }
        }
        return maxi;
    }
};
