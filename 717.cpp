class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool bit1=false;
        for(int i=0;i<bits.size();){
            if(i==bits.size()-1)
            {
                bit1=true;
                break;
            }
            else if(bits[i]==1)
                i+=2;
            else
                i++;
        }
        return bit1;
    }
};
