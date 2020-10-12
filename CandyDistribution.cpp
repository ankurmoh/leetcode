class Solution {
public:
    int candy(vector<int>& ratings) {
        int i,n=ratings.size(),tot=0;
        if(n==0)
            return n;
        vector<int>left(n,1);
        vector<int>right(n,1);
        for(i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                left[i]=left[i-1]+1;
        }
        for(i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                right[i]=right[i+1]+1;
        }
        for(i=0;i<n;i++)
            tot=tot+max(left[i],right[i]);
        return tot;
    }
};
