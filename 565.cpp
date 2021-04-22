class Solution {
public:
    int arrayNesting(vector<int>& nums) {
//         int maxi=INT_MIN;
//         map<int,int> m; 
//         vector<bool> vis(nums.size(),false);
//         for(int i=0;i<nums.size() && !vis[i];i++){
//             set<int> s;
//             int x=i;r
//             while(s.find(nums[x])==s.end() && !vis[x]){
//                 s.insert(nums[x]);
//                 x=nums[x];
//                 vis[x]=true;
//             }
//             maxi=max(maxi,(int)s.size());
//         }
//         return maxi;
        
        int maxi=0;
        
        for(int i=0;i<nums.size();i++){
            int x=i;
            int cnt=0;
            while(nums[x]!=-1){
                cnt++;
                int a=nums[x];
                nums[x]=-1;
                x=a;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
