class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)
            return "0";
        string ans="";
        int x=abs(num);
        while(x!=0){
            ans+=(x%7 + '0');
            x/=7;
        }
        reverse(ans.begin(),ans.end());
        if(num<0)
            ans="-"+ans;
        return ans;
    }
};
