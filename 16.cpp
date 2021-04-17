class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=INT_MAX,sum;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            
            if(i>0 && nums[i]==nums[i-1])continue;
            
            int l=i+1,r=n-1;
            while(l<r){
                int s=nums[i]+nums[l]+nums[r];
                if(ans>abs(s-target))
                {
                    ans=abs(s-target);
                    sum=s;
                }
                
                if(s<target)
                    l++;
                else if(s>target)
                    r--;
                else{
                    return s;
                }
            }
        }
        return sum;
    }
};
