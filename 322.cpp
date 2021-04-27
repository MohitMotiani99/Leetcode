class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         int dp[n+1][amount+1];
        
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=amount;j++){
//                 if(j==0)
//                     dp[i][j]=0;
//                 else if(i==0)
//                     dp[i][j]=1e7;
//                 else if(j>=coins[i-1])
//                     dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
//                 else
//                     dp[i][j]=dp[i-1][j];
//             }
//         }
//         if(dp[n][amount]>=1e7)
//             return -1;
//         return dp[n][amount];
        
        int dp[amount+1];
        //memset(dp,1e7,sizeof(dp));
        for(int i=0;i<=amount;i++)
            dp[i]=1e7;
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                if(j>=coins[i])
                    dp[j]=min(dp[j],1+dp[j-coins[i]]);
            }
        }
        
        return dp[amount]>=1e7?-1:dp[amount];
    }
};
