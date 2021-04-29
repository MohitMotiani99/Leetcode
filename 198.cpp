class Solution {
public:
    // int ans(vector<int> nums,int ind){
    //     if(ind>=nums.size())
    //         return 0;
    //     return max(nums[ind]+ans(nums,ind+2),ans(nums,ind+1));
    // }
    int rob(vector<int>& nums) {
        //return ans(nums,0);
        
        int n=nums.size();
        int dp[n][2];
        dp[0][0]=nums[0];
        dp[0][1]=0;
        
        for(int i=1;i<n;i++){
            dp[i][0]=nums[i]+dp[i-1][1];
            dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
        }
        
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
