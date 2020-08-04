class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool>res;
        if(A.size()==0)
            return res;
        long long int i,sz=A.size(),val=A[0],con=0;
        if(val%5==0)
            res.push_back(true);
        else
            res.push_back(false);
        for(i=1;i<sz;i++)
        {
            val = (2*val + A[i])%5;
            if(val==0)
            res.push_back(true);
        else
            res.push_back(false);
        }
        return res;
    }
};
