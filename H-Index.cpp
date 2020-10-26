class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i,n=citations.size();
        if(n==0)
            return 0;
    vector<int>count(n+1,0);
        for(i=0;i<n;i++)
        {
            if(citations[i]>=n)
                count[n]++;
            else
                count[citations[i]]++;
        }

        for(i=n-1;i>=0;i--)
            count[i]=count[i]+count[i+1];
        for(i=n;i>=0;i--)
        {
            if(count[i]>=i)
                return i;
        }
        return -1;
    }
};
