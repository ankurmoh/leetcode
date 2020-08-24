class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
       unordered_map<int,int>mp1;

       int i,j,sz1,sz2,sz3,sz4,ans=0,sum;
        sz1=A.size();
        sz2=B.size();
        sz3=C.size();
        sz4=D.size();
        if((sz1==0) || (sz2==0) || (sz3==0) || (sz4==0))
            return 0;
        for(i=0;i<sz1;i++)
        {
            for(j=0;j<sz2;j++)
            {
                mp1[A[i]+B[j]]++;
            }
        }
        for(i=0;i<sz3;i++)
        {
            for(j=0;j<sz4;j++)
            {
                sum=-(C[i]+D[j]);
                ans=ans+mp1[sum];
            }
        }
        return ans;
    }
};
