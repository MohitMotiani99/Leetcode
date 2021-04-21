class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int c=2;
        if(nums.size()<3)
            return 0;
        int ans=0;
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                c++;
            else{
                if(c>=3){
                    ans+=((c*(c+1))/2 - c -c +1);
                }
                c=2;
            }
        }
        if(c>=3){
                    ans+=((c*(c+1))/2 - c -c +1);
        }
        return ans;
    }
};
