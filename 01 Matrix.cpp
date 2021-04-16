class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//         vector<vector<int> > ans(matrix.size(),vector<int>(matrix[0].size(),-1));
        
//         int m=matrix.size();
//         int n=matrix[0].size();
        
        
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(ans[i][j]==-1){
//                     if(matrix[i][j]==0)
//                         ans[i][j]=0;
//                     else{
//                         queue<pair<pair<int,int>,int> > q;
//                         q.push({{i,j},0});
//                         while(!q.empty()){
//                             pair<pair<int,int>,int> p=q.front();
//                             q.pop();
//                             int x=p.first.first;
//                             int y=p.first.second;
//                             if(matrix[x][y]==0){
//                                 ans[i][j]=p.second;
//                                 break;
//                             }
//                             else{
//                                 if(x-1>=0 && ans[x-1][y]==-1)
//                                     q.push({{x-1,y},p.second+1});
//                                 if(x+1<m && ans[x+1][y]==-1)
//                                     q.push({{x+1,y},p.second+1});
//                                 if(y-1>=0 && ans[x][y-1]==-1)
//                                     q.push({{x,y-1},p.second+1});
//                                 if(y+1<n && ans[x][y+1]==-1)
//                                     q.push({{x,y+1},p.second+1});
//                             }
//                         }
//                     }
//                 }
                    
//             }
//         }
//         return ans;
        
//         int m=matrix.size();
//         int n=matrix[0].size();
        
//         vector<vector<int> > ans(m,vector<int>(n,INT_MAX));
//         queue<pair<int,int> > q;
        
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0)
//                 {
//                      ans[i][j]=0;
//                      q.push({i,j});
//                 }   
//             }
//         }
//         int arr[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//         while(!q.empty()){
//             pair<int,int> p=q.front();
//             q.pop();
//             for(int i=0;i<4;i++){
//                 int x=p.first+arr[i][0];
//                 int y=p.second+arr[i][1];
                
//                 if(x>=0 && x<m && y>=0 && y<n){
//                     if(ans[x][y]>ans[p.first][p.second]+1)
//                     {
//                         ans[x][y]=ans[p.first][p.second]+1;
//                         q.push({x,y});
//                     }
//                 }
//             }
//         }
        
//         return ans;
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int> > ans(m,vector<int>(n,INT_MAX-100000));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0)
                    ans[i][j]=0;
                else{
                    if(i>0)
                        ans[i][j]=min(ans[i][j],ans[i-1][j]+1);
                    if(j>0)
                        ans[i][j]=min(ans[i][j],ans[i][j-1]+1);
                }
            }
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
                    if(i<m-1)
                        ans[i][j]=min(ans[i][j],ans[i+1][j]+1);
                    if(j<n-1)
                        ans[i][j]=min(ans[i][j],ans[i][j+1]+1);
                
            }
        }
        return ans;
    }
};
