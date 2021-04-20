class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
//         vector<int> ans;
//         bool vis[A.size()];
//         for(int i=0;i<A.size();i++)
//             vis[i]=false;
//         for(int i=0;i<B.size();i++){
//             auto it=lower_bound(A.begin(),A.end(),B[i]);
//             if(it!=A.end()){
//                 int pos=it-A.begin();
//                 vis[pos]=true;
//                 ans.push_back(A[pos]);
//             }
//             else{
//                 int mini=INT_MAX,pos;
//                 for(int j=0;j<A.size();j++){
//                     if(!vis[j])
//                     {
//                         if(mini>A[j]){
//                             pos=j;
//                             mini=A[j];
//                         }
//                     }
//                 }
//             }
            
            
            
//         }
        
        
//         sort(A.begin(),A.end());
//         vector<int> ans;
//         int m=A.size(),n=B.size();
//         bool vis[m];
//         //memset(vis,false,sizeof(vis));
//         for(int i=0;i<m;i++)vis[i]=false;
        
//         for(int i=0;i<n;i++){
//             int j;
            
//             for(j=0;j<m;j++){
//                 if(!vis[j] && A[j]>B[i])
//                     break;
//             }
//            // cout<<j<<endl;
//             if(j!=m)
//             {
//                 ans.push_back(A[j]);
//                 vis[j]=true;
//             }
//             else{
//                 int j;
//                 for(j=0;j<m;j++){
//                     if(!vis[j])
//                         break;
//                 }
//                 ans.push_back(A[j]);
//                 vis[j]=true;

//             }
            
//         }
        
//         return ans;
        
        //vector<int> t=B;
        int m=A.size(),n=B.size();
        //sort(A.begin(),A.end());
        multiset<int> s(A.begin(),A.end());
        //vector<int> ans;
        
        for(int i=0;i<n;i++){
            
            if(B[i]>= *s.rbegin()){
                A[i]=*s.begin();
                s.erase(s.begin());
            }
            else{
                auto it=s.upper_bound(B[i]);
                A[i]=*it;
                s.erase(it);
            }
        }
        
        return A;
        
    }
};
