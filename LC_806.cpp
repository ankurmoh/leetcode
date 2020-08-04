class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int>res(2,0);

        int i,j,len1=S.length(),cur=0,ind=1;
        for(i=0;i<len1;i++)
        {
            cur=cur+widths[S[i]-'a'];
            if(cur>100)
            {
                ind++;
                cur=widths[S[i]-'a'];
            }
        }
        res[0]=ind;
        res[1]=cur;
        return res;
    }
};
