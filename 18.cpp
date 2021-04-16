class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         map<int,vector<pair<int,int>>> m;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 m[nums[i]+nums[j]].push_back({i,j});
//             }
//         }
//         set<vector<int> > ans;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 auto it=m.find(target-nums[i]-nums[j]);
//                 if(it!=m.end()){
//                     vector<pair<int,int> > t=it->second;
                    
//                     for(int p=0;p<t.size();p++){
//                         if(t[p].first!=i  && t[p].second!=j && t[p].first!=j && t[p].second!=i)
//                         {
//                             vector<int> t2(4);
//                             t2[0]=nums[i];t2[1]=nums[j];
//                             t2[2]=nums[t[p].first];t2[3]=nums[t[p].second];
//                             sort(t2.begin(),t2.end());
//                             ans.insert(t2);
//                         }
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans2;
//         for(auto i:ans)
//             ans2.push_back(i);
//         return ans2;
        
//         int n=nums.size();
//         set<vector<int> > ans;
//         for(int i=0;i<n-3;i++){
//             for(int j=i+1;j<n-2;j++){
//                 for(int k=j+1;k<n-1;k++){
//                     for(int l=k+1;l<n;l++){
//                         if(nums[i]+nums[j]+nums[k]+nums[l]==target){
//                             vector<int> t;
                            
//                             t.push_back(nums[i]);
//                             t.push_back(nums[j]);
//                             t.push_back(nums[k]);
//                             t.push_back(nums[l]);
                            
//                             sort(t.begin(),t.end());
                            
//                             ans.insert(t);
//                         }
//                     }
//                 }
//             }
//         }
//         //return ans;
//         vector<vector<int>> ans2;
//        for(auto i:ans)
//             ans2.push_back(i);
//         return ans2;
        
        
        vector<vector<int> > ans;
        int n=nums.size();
        if(n<4)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target)continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target)continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum>target)
                        right--;
                    else if(sum<target)
                        left++;
                    else{
                        ans.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1] && left<right);
                        do{right--;}while(nums[right]==nums[right+1] && left<right);
                    }
                }
            }   
        }
        return ans;
    }
};
