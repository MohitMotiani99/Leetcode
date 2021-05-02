class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> dp(n,1);
        // dp[0]=1;
        // for(int i=1;i<n;i++){
        //     for(int j=i-1;j>=0;j--)
        //     {
        //         if(nums[i]>nums[j])
        //             dp[i]=max(dp[i],1+dp[j]);
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());
        
        int n=nums.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0]=INT_MIN;
        for(int i=0;i<n;i++){
            int pos=upper_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            if(nums[i]>dp[pos-1])dp[pos]=nums[i];
        }
        for(int i=n;i>=0;i--)
        {
            if(dp[i]!=INT_MAX)
                return i;
        }
        return -1;
        
        // int n=nums.size();
        // vector<int> s;
        // for(int i=0;i<n;i++){
        //     auto it=lower_bound(s.begin(),s.end(),nums[i]);
        //     if(it==s.end())s.push_back(nums[i]);
        //     else 
        //         *it=nums[i];
        // }
        // return s.size();
    }
};
