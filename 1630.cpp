class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        // for(int i=0;i<l.size();i++){
        //     vector<int> t{nums.begin()+l[i],nums.begin()+r[i]+1};
        //     // for(int j=0;j<t.size();j++)
        //     //     cout<<t[j]<<" ";
        //     // cout<<endl;
        //     sort(t.begin(),t.end());
        //     if(t.size()<2)
        //         ans.push_back(false);
        //     else{
        //         int j;
        //         for(j=2;j<t.size();j++){
        //             if(t[j]-t[j-1]!=t[1]-t[0])
        //                 break;
        //         }
        //         if(j==t.size())
        //             ans.push_back(true);
        //         else
        //             ans.push_back(false);
        //     }
        // }
        
        
        for(int i=0;i<l.size();i++){
            int mx,mn;
            mx=*max_element(nums.begin()+l[i],nums.begin()+r[i]+1);
            mn=*min_element(nums.begin()+l[i],nums.begin()+r[i]+1);
            
            int len=r[i]-l[i]+1;
            if(mx==mn)
                ans.push_back(true);
            else if((mx-mn)%(len-1))
                ans.push_back(false);
            else{
                vector<bool> vis(len,false);
                int pat=(mx-mn)/(len-1);
                int j;
                for(j=l[i];j<=r[i];j++){
                    if((nums[j]-mn)%pat || vis[(nums[j]-mn)/pat])
                        break;
                    vis[(nums[j]-mn)/pat]=true;
                }
                if(j==r[i]+1)
                    ans.push_back(true);
                else
                    ans.push_back(false);
            }
        }
        return ans;
    }
};
