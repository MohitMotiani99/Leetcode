class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1])
        //         return nums[i];
        // }
        // return -1;
        
        // unordered_map<int,int> m;
        // for(int i=0;i<nums.size();i++){
        //     m[nums[i]]++;
        //     if(m[nums[i]]>1)
        //         return nums[i];
        // }
        // return -1;
        
//         for(int i=0;i<nums.size();i++){
//             int index=abs(nums[i])-1;
//             nums[index]*=-1;
//             if(nums[index]>0)
//                 return abs(nums[i]);
//         }
        
//         return -1;
        
//         int slow=nums[0],fast=nums[0];
//         do{
//             slow=nums[slow];
//             fast=nums[nums[fast]];
//         }while(slow!=fast);
        
//         slow=nums[0];
//         while(slow!=fast){
//             slow=nums[slow];
//             fast=nums[fast];
//         }
//         return slow;
        
        //Pegion hole
        
        int low=1,high=nums.size()-1,mid;
        while(low<high){
            mid=(low+high)/2;
            
            int c=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=mid)
                    c++;
            }
            
            if(c>mid)
                high=mid;
            else
                low=mid+1;
        }
        return high;
    }
};
