class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return false;
//         else{
//             int i=0,j=0;
//             int maxh=INT_MIN;
            
//             bool found=false;
            
//             while(1){
//                 if(i==n-2)
//                     break;
//                 else if(j==n)
//                 {
//                     i++;
//                     j=i;
//                     maxh=INT_MIN;
//                 }
//                 else if(i==j)
//                 {
//                     j++;
//                     maxh=INT_MIN;
//                 }
//                 else if(nums[j]>maxh && nums[j]>nums[i])
//                     maxh=nums[j],j++;
//                 else if(maxh!=INT_MIN && nums[j]>nums[i] && nums[j]<maxh)
//                 {
//                     found=true;
//                     break;
//                 }
//                 else
//                     j++;
//             }
//             return found;
//         }
        
        
        bool found=false;
        stack<int> s;
        //s.push(nums[n-1]);
        //vector<int> v;
        int prev=INT_MIN;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i]>s.top()){
                if(s.top()<prev)
                    return true;
                prev=s.top();
                //v.push_back(s.top());
                s.pop();
            }
            
            s.push(nums[i]);
            
            // for(int i=0;i<v.size();i++)
            // cout<<v[i]<<" ";
            // cout<<endl;
            
        }
        
        // while(!s.empty()){
        //     v.push_back(s.top());
        //     s.pop();
        // }
        
        // for(int i=0;i<v.size();i++)
        //     cout<<v[i]<<" ";
        // cout<<endl;
        
        
        // for(int i=1;i<v.size();i++){
        //     if(v[i]<v[i-1])
        //         return true;
        // }
        return !s.empty() && prev>s.top();
    }
};


/*






*/
