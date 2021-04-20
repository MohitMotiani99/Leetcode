class Solution {
public:
    void static dfs(vector<vector<int>>& graph,vector<int>& path,vector<vector<int>>& ans,int s){
        if(path.back()==graph.size()-1){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<graph[s].size();i++){
            path.push_back(graph[s][i]);
            dfs(graph,path,ans,graph[s][i]);
            path.pop_back();
        }     
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int> > ans;
        path.push_back(0);
        dfs(graph,path,ans,0);
        
        return ans;
    }
};
