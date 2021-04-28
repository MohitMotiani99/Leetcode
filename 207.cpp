class Solution {
public:
    bool iscycle(vector<int>& vis,vector<vector<int> > adj,int s){
        if(vis[s]==1)
            return true;
        if(vis[s]==0){
            vis[s]=1;
            for(auto edge:adj[s]){
                if(iscycle(vis,adj,edge))
                    return true;
            }
                
        }
        vis[s]=2;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
//         vector<int> vis(n,0);
        
//         vector<vector<int> > adj(n);
//         for(int i=0;i<p.size();i++)
//             adj[p[i][1]].push_back(p[i][0]);
        
//         for(int i=0;i<n;i++){{
//             if(vis[i]==0){
//                 if(iscycle(vis,adj,i))
//                 return false;    
//             }
//             else if(vis[i]==1)
//                 return false;
//         }
            
//         }
//         return true;
        
        vector<int> indegree(n,0);
        vector<int> bfs;
        vector<vector<int>> adj(n);
        for(auto a:p)
            adj[a[1]].push_back(a[0]),indegree[a[0]]++;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                bfs.push_back(i);
            }
        }
        for(int i=0;i<bfs.size();i++){
            for(int j:adj[bfs[i]]){
                if(--indegree[j]==0)
                    bfs.push_back(j);
            }
        }
        return bfs.size()==n;
    }
};
