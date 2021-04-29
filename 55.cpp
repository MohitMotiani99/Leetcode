class Solution {
public:
    // bool jump(vector<int> nums,int ind){
    //     if(ind==nums.size()-1)
    //         return true;
    //     for(int i=1;i<=nums[ind];i++){
    //         if(ind+i==nums.size()-1)
    //             return true;
    //         if(ind+i>=nums.size())
    //             break;
    //         if(jump(nums,ind+i))
    //             return true;
    //     }
    //     return false;
    // }
     bool canJump(vector<int>& nums) {
    //     return jump(nums,0);
    // }
    int n=nums.size();
    int step=nums[0];
         for(int i=1;i<n;i++){
             step--;
             if(step<0)
                 return false;
             if(nums[i]>step)
                 step=nums[i];
         }
         return true;
     }
};
