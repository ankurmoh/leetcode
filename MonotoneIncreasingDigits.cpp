class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int i,len,mark=-1;
        string temp = to_string(N);
        len=temp.length();
        for(i=len-1;i>0;i--)
        {
            if(temp[i]<temp[i-1])
            {
                mark=i;
                temp[i-1]=temp[i-1]-1;
            }
        }
        if(mark==-1)
            return stoi(temp);
        for(i=mark;i<len;i++)
            temp[i]='9';
        return stoi(temp);
    }
};
