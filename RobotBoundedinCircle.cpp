class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>>dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        int d=0,i,len=instructions.length(),x=0,y=0;
        for(i=0;i<len;i++)
        {
            if(instructions[i]=='R')
                d=(d+1)%4;
            else if(instructions[i]=='L')
                d=(d+3)%4;
            else
            {
                x=x+dir[d][0];
                y=y+dir[d][1];
            }
        }
        if((x == 0) && (y==0))
            return true;
        if(d!=0)
            return true;
        return false;
    }
};
