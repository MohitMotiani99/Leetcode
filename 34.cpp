class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l=0,h=nums.size()-1,m;
        vector<int> ans;
        while(l<=h){
            m=(l+h)/2;
            if(nums[m]==target){
                while(m>0 && target==nums[m-1])
                    m--;
                ans.push_back(m);
                break;
            }
            else if(nums[m]<target)
                l=m+1;
            else
                h=m-1;
        }
        if(ans.size()==0)
            ans.push_back(-1);
        
        l=0;
        h=nums.size()-1;
        
        
        while(l<=h){
            m=(l+h)/2;
            if(nums[m]==target){
                while(m<nums.size()-1 && target==nums[m+1])
                    m++;
                ans.push_back(m);
                break;
            }
            else if(nums[m]<target)
                l=m+1;
            else
                h=m-1;
        }
        
        if(ans.size()==1)
            ans.push_back(-1);
        
        return ans;
        
    }
};
