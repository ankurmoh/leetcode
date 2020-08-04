class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        int i,flag,dig;
        vector<int>res;
        for(i=left;i<=right;i++)
        {
            int temp=i;
            flag=0;
            while(temp>0)
            {
                dig=temp%10;
                if((dig==0) || (i%dig!=0))
                {
                    flag=1;
                    break;
                }
                temp=temp/10;
            }
            if(!flag)
                res.push_back(i);
        }
        return res;
    }
};
