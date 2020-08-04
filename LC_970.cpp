class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int i,j;
        set<int>st;
        for(i=0;i<=19 && pow(x,i)<=bound;i++)
        {
            for(j=0; j<=19 && pow(y,j)<=bound;j++)
            {
                if(pow(x,i)+pow(y,j)<=bound)
                    st.insert(pow(x,i)+pow(y,j));
            }
        }
        vector<int>res(st.begin(),st.end());
        return res;
    }
};
