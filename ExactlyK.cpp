class Solution {
public:
    int atmost(vector<int>& A,int K)
    {
        int left=0,right=0,sz=A.size(),con=0,s=0;
        unordered_map<int,int>mp;
        for(right=0;right<sz;right++)
        {
            mp[A[right]]++;
            con = mp.size();
            while((con>K) && (left<=right))
            {
                mp[A[left]]--;
                if(mp[A[left]]==0)
                {
                    mp.erase(A[left]);
                    con--;
                }
                left++;
            }
            s=s + (right-left+1);
        }
        return s;
    }
    int subarraysWithKDistinct(vector<int>& A, int K)
    {
        return ((atmost(A,K)) - (atmost(A,K-1)));
    }
};
