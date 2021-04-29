class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int n=nums.size();
        // int a[n],b[n];
        // a[0]=nums[0];
        // for(int i=1;i<n;i++)a[i]=min(nums[i],a[i-1]);
        // b[n-1]=nums[n-1];
        // for(int i=n-2;i>=0;i--)b[i]=max(nums[i],b[i+1]);
        // for(int i=0;i<n;i++)if(a[i]<nums[i] && nums[i]<b[i])return true;
        // return false;
        
        int n=nums.size();
        int a=INT_MAX,b=INT_MAX;
        for(int i=0;i<n;i++){
            if(a>=nums[i])a=nums[i];
            else if(b>=nums[i])b=nums[i];
            else return true;
        }
        return false;
    }
};
