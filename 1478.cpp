class Solution {
public:
    int cost[101][101],dp[101][101];
    // int dfs(vector<int> houses,int s,vector<int>& mind,int k){
    //     if(k==0){
    //         int sum=0;
    //         for(int i=0;i<houses.size();i++)
    //             sum+=mind[i];
    //         return sum;
    //     }
    //     int minans=INT_MAX;
    //     for(int i=s;i<=houses.back();i++){
    //         vector<int> t=mind;
    //         for(int j=0;j<houses.size();j++){
    //             if(t[j]>abs(i-houses[j]))
    //                 t[j]=abs(i-houses[j]);
    //         }
    //         minans=min(minans,dfs(houses,s+1,t,k-1));
    //     }
    //     return minans;
    // }
    int dfs(vector<int>& houses, int k,int start){
        int n=houses.size();
        if(k==0 && start==n)return 0;
        if(k==0 || start==n)return 1e7;
        if(dp[k][start]!=-1)return dp[k][start];
        int minans=INT_MAX;
        for(int i=start;i<n;i++){
            minans=min(minans,cost[start][i]+dfs(houses,k-1,i+1));
        }
        return dp[k][start]=minans;
    }
     int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
    //     vector<int> mind(houses.size(),INT_MAX);
    //     return dfs(houses,houses[0],mind,k);
         
         int n=houses.size();
         for(int i=0;i<n;i++){
             for(int j=i;j<n;j++){
                 for(int x=i;x<=j;x++)
                     cost[i][j]+=abs(houses[x]-houses[(i+j)/2]);
             }
         }
         
         memset(dp,-1,sizeof(dp));
         return dfs(houses,k,0);
     }
    
    
};
