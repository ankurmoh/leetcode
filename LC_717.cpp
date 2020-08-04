class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
       int i=0,len=bits.size();
       while(i<len)
       {
           if(bits[i]==1)
           {
               i=i+2;
           }
           else if(bits[i]==0)
           {
               if(i==len-1)
                   return true;
               else
                   i=i+1;
           }
       }
        return false;
    }
};
