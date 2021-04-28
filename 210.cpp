class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> bfs;
        vector<int> indegree(n,0);
        vector<vector<int> > g(n);
        
        for(auto e:p)
            g[e[1]].push_back(e[0]),indegree[e[0]]++;
        for(int i=0;i<n;i++)if(indegree[i]==0)bfs.push_back(i);
        for(int i=0;i<bfs.size();i++){
            for(int j:g[bfs[i]]){
                if(--indegree[j]==0)bfs.push_back(j);
            }
            // for(int j=0;j<g[bfs[i]].size();j++){
            //     indegree[g[bfi][j]]--;
            //     if(indegree[g[i][j]]==0)
            //         bfs.push_back(g[i][j]);
            // }
        }
        // for(int i=0;i<bfs.size();i++)
        //     cout<<bfs[i]<<" ";
        // cout<<endl;
        return (bfs.size()==n)?bfs:vector<int>{};
    }
};
