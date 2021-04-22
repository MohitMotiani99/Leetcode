class Solution {
public:
    int arrangeCoins(int n) {
        // int c=n;
        // int i;
        // for(i=1;i<=n;i++){
        //     if(c>=i)
        //         c-=i;
        //     else
        //         break;
        // }
        // return i-1;
        
        long long int l=1,r=100000,m,x;
        while(l<=r){
            m=(l+r)/2;
            if((m*(m+1))/2 >n)
                r=m-1;
            else if((m*(m+1))/2 <=n)
                x=m,l=m+1;
                
        }
        return x;
    }
};
