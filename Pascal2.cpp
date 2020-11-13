class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        //vector<int>v(rowIndex+1,1);
        vector<int>v,prev{1};
        int i,j,sz,k;
        for(i=0;i<=rowIndex;i++)
        {
            v.resize(i+1);
            //fill(v.begin(),v.end(),1);
            v[0] = v[i] = 1;
            for(j=1;j<i;j++)
                v[j]=prev[j]+prev[j-1];
            prev = v;
        }
        return prev;
    }
};
