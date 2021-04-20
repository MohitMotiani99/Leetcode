class Solution {
public:
//    bool static cmp(pair<string,string> a,pair<string,string> b){
//         if(a.first!=b.first)
//             return a.first<b.first;
//         else
//             return a.second<b.second;
//     }
     vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
//         vector<pair<string,string> > v;
//         int n=keyName.size();
//         for(int i=0;i<n;i++){
//             v.push_back({keyName[i],keyTime[i]});
//         }
//         sort(v.begin(),v.end(),cmp);
//         vector<string> ans;
        
//         for(int i=0;i<n;i++)
//             cout<<v[i].first<<" "<<v[i].second<<endl;
        
        
//         int c=1;
//         int i;
//         for(i=1;i<n;i++){
//             if(v[i].first==v[i-1].first){
//                 if(v[i].second.substr(0,2)==v[i-1].second.substr(0,2))
//                     c++;
//                 else if(stoi(v[i].second.substr(0,2))==stoi(v[i-1].second.substr(0,2))+1 && v[i].second.substr(3)=="00")
//                     c++;
//                 else{
//                     if(c>=3 && (ans.size()==0 || ans.back()!=v[i-1].first))
//                         ans.push_back(v[i-1].first);
//                     c=1;
//                 }
//             }
//             else{
//                 if(c>=3 && (ans.size()==0 || ans.back()!=v[i-1].first))
//                         ans.push_back(v[i-1].first);
//                 c=1;
//             }
//         }
//         if(c>=3 && (ans.size()==0 || ans.back()!=v[i-1].first))
//                         ans.push_back(v[i-1].first);
//         c=1;
//         return ans;
    
    unordered_map<string ,vector<int> > m;
    int n=keyTime.size();
    for(int i=0;i<n;i++){
        m[keyName[i]].push_back(stoi(keyTime[i].substr(0,2))*60+stoi(keyTime[i].substr(3)));
    }
    vector<string> ans;
    for(auto i:m){
        sort(begin(i.second),end(i.second));
        for(int j=0;j+2<i.second.size();j++){
            int k=j+2;
            if(i.second[k]-i.second[j]<=60)
            {
                ans.push_back(i.first);
                break;
            }
        }
    }
     sort(ans.begin(),ans.end());
    return ans;
    }
};
