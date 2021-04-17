class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort(nums.begin(),nums.end());c
        // set<vector<int> > s;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(binary_search(nums.begin()+j+1,nums.end(),-(nums[i]+nums[j])))
        //         {
        //             vector<int> t;
        //             t.push_back(nums[i]);
        //             t.push_back(nums[j]);
        //             t.push_back(-(nums[i]+nums[j]));
        //             sort(t.begin(),t.end());
        //             s.insert(t);
        //         }
        //     }
        // }
        // vector<vector<int> > ans;
        // for(auto i:s)
        //     ans.push_back(i);
        // return ans;
        
//         vector<vector<int> > ans;
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         unordered_map<int,int> m;
//         for(int i=0;i<n;i++)
//             m[nums[i]]++;
//         for(int i=0;i<n-2;i++){
            
//             if(i>0 && nums[i]==nums[i-1])continue;
//             if(nums[i]+nums[i+1]+nums[i+2]>0)break;
//             if(nums[i]+nums[n-2]+nums[n-1]<0)continue;
            
            
//             for(int j=i+1;j<n-1;j++){
                
//                 if(j>i+1 && nums[j]==nums[j-1])continue;
//                 if(nums[i]+nums[j]+nums[j+1]>0)break;
//                 if(nums[i]+nums[j]+nums[n-1]<0)continue;
// //                 auto it=binary_search(nums.begin(),nums.end(),0-nums[i]-nums[j]);
                
// //                 if(it){
// //                     //int k=it-nums.begin();
// //                     ans.push_back(vector<int>{nums[i],nums[j],0-nums[i]-nums[j]});
// //                 }
//                 //int amt=m[0-nums[i]-nums[j]]
//                 if(m[0-nums[i]-nums[j]]){
//                     ans.push_back(vector<int>{nums[i],nums[j],0-nums[i]-nums[j]});
//                 }
//             }
        
//         }
        
//         return ans;
        
        vector<vector<int> > ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            
            if(i>0 && nums[i]==nums[i-1])continue;                                                       if(nums[i]+nums[i+1]+nums[i+2]>0)break;
            if(nums[i]+nums[n-2]+nums[n-1]<0)continue;
            
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum>0)
                    r--;
                else if(sum<0)
                    l++;
                else{
                    ans.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    do{l++;}while(nums[l]==nums[l-1] && l<r);
                    do{r--;}while(nums[r]==nums[r+1] && l<r);
                }

            }
        }
        
        return ans;
    }
};
