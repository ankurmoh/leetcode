class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int zero=0,n=A.size(),left=0,right,maxlen=0;
        for(right=0;right<n;right++)
        {
            if(A[right]==0)
                zero++;
            while(zero>K)
            {
                if(A[left]==0)
                    zero--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};
