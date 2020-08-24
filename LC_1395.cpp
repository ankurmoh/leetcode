class Solution {
public:
    int numTeams(vector<int>& rating) {
        int i,j,k,len=rating.size(),con=0;
        for(i=0;i<len;i++)
        {
            int leftlower=0,righthigher=0,lefthigher=0,rightlower=0;
            for(j=i-1;j>=0;j--)
            {
                if(rating[j]<rating[i])
                    leftlower++;
                else if(rating[j]>rating[i])
                    lefthigher++;
            }
            for(j=i+1;j<len;j++)
            {
                if(rating[j]>rating[i])
                    righthigher++;
                else if(rating[j]<rating[i])
                    rightlower++;
            }
            con=con + (leftlower*righthigher) + (lefthigher*rightlower);
        }
        return con;
    }
};
