class Solution {
public:
    int divide(int dividend, int divisor) {
        // if(div==INT_MAX && divi==1)return INT_MAX;
        // if(div==INT_MIN && divi==1)return INT_MIN;
//         long dividend=div;
//         long divisor=divi;
//         int c=0;
//         bool neg=false;
//         if((dividend<0 && divisor>0 )||(dividend>0 && divisor<0 ))
//             neg=true;
//         dividend=labs(dividend);
//         divisor=labs(divisor);
        
//         //cout<<dividend<<"  "<<divisor<<"   ";
//         while(dividend>=divisor){
//             c++;
//             if(c==INT_MAX){
//                 break;
//             }
//             dividend-=divisor;
//         }
//         //cout<<c<<endl;
//         if(neg)
//             return -1*c;
//         else
//             return c;
        
        if(dividend==INT_MIN && divisor==-1)return INT_MAX;
        if(dividend==INT_MAX && divisor==-1)return INT_MIN;
        if(dividend==INT_MIN && divisor==1)return INT_MIN;
        if(dividend==INT_MAX && divisor==1)return INT_MAX;
        
        long div=abs(dividend);
        long divi=abs(divisor);
        
        long ans=0;
        while(div>=divi){
            long temp=divi,m=1;
            while(temp<<1 <=div){
                temp=temp<<1;
                m*=2;
            }
            ans+=m;
            div-=temp;
        }
        if((dividend<0 || divisor<0) && !(dividend<0 && divisor<0))
        return -ans;
        return ans;
    }
};
