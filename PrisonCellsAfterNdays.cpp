class Solution {
public:
    vector<int> next(vector<int>& v1)
    {
        vector<int>temp(8);
        int j;
        for(j=0;j<8;j++)
        {
            if((j==0) || (j==7))
                temp[j]=0;
            else
            {
                if(v1[j-1]==v1[j+1])
                    temp[j]=1;
                else
                    temp[j]=0;
            }
        }
        return temp;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int>v1=cells;
        int i,j,cyc=0;
        string temp="",temp1="";
        unordered_set<string>s;
        for(i=1;i<=N;i++)
        {
            temp="";
            v1=next(cells);
            for(j=0;j<8;j++)
                temp=temp+char(v1[j]);
            if(!s.count(temp))
            {
                cyc++;
                s.insert(temp);
            }
            else if(s.count(temp))
                break;
            cells = v1;
        }
        N=N%cyc;
        for(i=1;i<=N;i++)
        {
            v1=next(cells);
            cells=v1;
        }
        return cells;
    }
};
