class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        //map<int,int> m;
//         map<int,bool> vis;
//         for(int i=0;i<rains.size();i++){
//             if(rains[i]!=0)
//                 vis[rains[i]]=false;
//         }
//         vector<int> ans;
        
//         for(int i=0;i<rains.size();i++){
//             if(rains[i]==0){
                
                
//                 int j=i+1;
//                 for(;j<rains.size();j++){
//                     if(vis[rains[j]])
//                         break;
//                 }
//                 if(j<rains.size()){
//                     ans.push_back(rains[j]);
//                     vis[rains[j]]=false;
//                 }
//                 else
//                     ans.push_back(1);
                
//                 // cout<<"H1"<<"      ";
//                 // for(int j=0;j<ans.size();j++)
//                 //     cout<<ans[j]<<" ";
//                 // cout<<endl;
//             }
//             else{
//                 if(vis[rains[i]])
//                     return vector<int>{};
                
//                 ans.push_back(-1);
//                 vis[rains[i]]=true;
                
//                 // cout<<"H2"<<"      ";
//                 // for(int j=0;j<ans.size();j++)
//                 //     cout<<ans[j]<<" ";
//                 // cout<<endl;
//             }
//         }
//         return ans;
        
        vector<int> ans;
        unordered_map<int,int> fulllakes;
        set<int> drydays;
        
        for(int i=0;i<rains.size();i++){
            if(rains[i]==0){
                drydays.insert(i);
                ans.push_back(1);
            }
            else{
                if(fulllakes.find(rains[i])!=fulllakes.end()){
                    auto it=drydays.lower_bound(fulllakes[rains[i]]);
                    if(it==drydays.end())
                        return {};
                    int dryday=*it;
                    ans[dryday]=rains[i];
                    drydays.erase(dryday);
                    
                }
                fulllakes[rains[i]]=i;
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
