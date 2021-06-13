class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s.size()==0)
             return 0;
//         int i=0,j=0;
//         vector<bool> vis(256,false);
//         int ans=INT_MIN;
//         while(i<=j && j<s.size() ){
//             if(vis[s[j]]==false){
//                 vis[s[j]]=true;
//                 j++;
//                 ans=max(ans,j-i);
//                 //cout<<"H1 "<<i<<" "<<j<<" "<<ans<<endl;
//                 //j++;
//             }
//             else{
                
//                 int k;
//                 for(k=j-1;k>=i;k--)
//                 {
//                     if(!(s[k]!=s[j] && vis[s[k]]==true))
//                         break;
//                 }
                
                
//                 i=k+1;
//                 vis[s[j]]=true;
//                 j++;
//                 ans=max(ans,j-i);
//                 //cout<<"H2 "<<i<<" "<<j<<" "<<ans<<endl;
//             }
//         }
//         ans=max(ans,j-i);
//         //cout<<"H3 "<<i<<" "<<j<<" "<<ans<<endl;
//         return ans;
        
        
        // int res=INT_MIN;
        // for(int i=0;i<s.size();i++){
        //     vector<bool> vis(256,false);
        //     for(int j=i;j<s.size();j++){
        //         if(vis[s[j]])
        //             break;
        //         else{
        //             res=max(res,j-i+1);
        //             vis[s[j]]=true;
        //         }
        //     }
        //     //vis[s[i]]=false;
        // }
        // return res;
        
        
        
        vector<int> li(256,-1);
        int i=0,res=INT_MIN;
        for(int j=0;j<s.size();j++){
            i=max(i,li[s[j]]+1);
            
            res=max(res,j-i+1);
            
            li[s[j]]=j;
        }
        
        return res;
    }
};
