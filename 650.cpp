class Solution {
public:
    int minSteps(int n) {
//         int dp[n+1];
//         memset(dp,INT_MAX,sizeof(dp));
//         dp[1]=0;
//         for(int i=2;i<=n;i++){
//             int j;
//             for(j=i-1;j>=2;j--){
//                 if(i%j==0)
//                 {
//                     dp[i]=1+dp[j]+i/j-1;
//                     break;
//                 }
//             }
            
//             if(j==1)
//                 dp[i]=i;
//         }
//         // for(int i=1;i<=n;i++)
//         //     cout<<dp[i]<<" ";
//         // cout<<endl;
//         return dp[n];
        
        if(n==1)
            return 0;
        int i;
        for(i=n-1;i>=2;i--){
            if(n%i==0)
                break;
        }
        if(i==1)
            return n;
        else
            return minSteps(i)+n/i;
    }
};
