class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
       sort(A.begin(),A.end());
        int i=0,j=A.size()-1,m=INT_MIN;
        while(i<j)
        {
         if(A[i]+A[j]>=K)
             j--;
            else if(A[i]+A[j]<K)
            {
                m=max(m,A[i]+A[j]);
                i++;
            }
        }
        if(m==INT_MIN)
            return -1;
        return m;
    }
};
