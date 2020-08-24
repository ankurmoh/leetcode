class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,sz=gas.size(),current_tank=0,total_tank=0,start=0;
        for(i=0;i<sz;i++)
        {
            total_tank=total_tank+gas[i]-cost[i];
            current_tank=current_tank+gas[i]-cost[i];
            if(current_tank<0)
            {
                current_tank=0;
                start=i+1;
            }
        }
        return total_tank>=0 ? start:-1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,sz=gas.size(),totalgas=0,totalcost=0,flag,pos,start;
        for(i=0;i<sz;i++)
        {
            flag=0;
            if(gas[i]>=cost[i])
            {
                start=i;
                totalgas=gas[i]-cost[i];
                pos=(start+1)%sz;
                while(pos!=start)
                {
                    totalgas=totalgas+gas[pos]-cost[pos];
                    if(totalgas<0)
                    {
                        flag=1;
                        break;
                    }
                    pos=(pos+1)%sz;
                }
                if((pos==start) && ((totalgas)>=0))
                    return start;
                else if(flag==1)
                    continue;
            }
        }
        return -1;
    }
};
