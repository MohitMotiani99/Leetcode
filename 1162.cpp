class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int> > dist(grid.size(),vector<int>(grid.size(),INT_MAX));
        queue<pair<int,int> > q;
        int n=grid.size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1)dist[i][j]=0,q.push({i,j});
            }
        }
        int maxi=INT_MIN;
        int arr[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            if(grid[p.first][p.second]==0)
                maxi=max(maxi,dist[p.first][p.second]);
            grid[p.first][p.second]=-1;
            
            
            for(int i=0;i<4;i++){
                int x=p.first+arr[i][0];
                int y=p.second+arr[i][1];
                
                if(x>=0 && y>=0 && x<n && y<n && grid[x][y]!=-1){
                    if(dist[p.first][p.second]+1<dist[x][y])
                    {
                        dist[x][y]=dist[p.first][p.second]+1;
                        q.push({x,y});
                    }
                }
            }
        }
        if(maxi==INT_MIN)
            return -1;
        return maxi;
    }
};
