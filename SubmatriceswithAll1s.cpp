class Solution {
public:
   /* int histogram(vector<int>& heights)
    {
        stack<int>st;
        st.push(-1);
        int i,ht,sz = heights.size(),res=0,index,range;
        vector<int>sum(sz,0);
        for(i=0;i<sz;i++)
        {
            while((st.top()!=-1) && (heights[st.top()]>=heights[i]))
            {
                ht = heights[st.top()];
                index = st.top();
                st.pop();
                range = i - s.top()-1;
                sum[i]=sum[i]+sum[index];
                sum[i]=sum[i] + (range*ht);
            }
            st.push(i);
        }
        while(st.top()!=-1)
        {
            ht=heights[st.top()];
            index=st.top();
            st.pop();
            range=i-s.top()-1;
            sum[i]=sum[i]
        }

        for(i=0;i<sz;i++)
            res=res+sum[i];
        return res;
    }*/
    int numSubmat(vector<vector<int>>& mat) {
     int i,j,row=mat.size(),col=mat[0].size(),res=0,width,k;
       // vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(mat[i][j]>0)
                {
                  //  if(j==0)
                    //    mat[i][j]=1;
                    if(j>=1)
                        mat[i][j]=1+mat[i][j-1];
                }
                width = mat[i][j];
                if(width == 0)
                    continue;
                for(k=i;k>=0;k--)
                {
                    width = min(width, mat[k][j]);
                    //cout<<width<<" "<<k<<" "<<j<<endl;
                    if(width == 0)
                        break;
                    res=res+width;
                }
            }
        }
        return res;
    }
};
