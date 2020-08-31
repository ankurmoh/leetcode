class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sz=A.size(),left,right,second,d,con=0,k,flag;
        for(left=0;left<sz-2;left++)
        {
            second=left+1;
            d=A[second]-A[left];
            for(right=left+2;right<sz;right++)
            {
                flag=0;
                for(k=left+1;k<=right;k++)
                {
                    if(A[k]-A[k-1]!=d)
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    con++;
            }
        }
      for(left=0;left<sz-2;left++)
        {
            second=left+1;
            d=A[second]-A[left];
            for(right=left+2;right<sz;right++)
            {
                if(A[right]-A[right-1]!=d)
                    break;
                else
                    con++;
            }
        }
        vector<int>dp(sz+1,0);
        for(left=2;left<sz;left++)
        {
            if(A[left]-A[left-1] == A[left-1]-A[left-2])
            {
                dp[left]=1+dp[left-1];
                con=con+dp[left];
            }
        }
        return con;
    }
};
