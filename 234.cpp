class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,int p,int q,int m,int n){
        vis[p][q]=true;
        if(p+1<m && board[p+1][q]=='X' && !vis[p+1][q])
            dfs(board,vis,p+1,q,m,n);
        
        if(q+1<n && board[p][q+1]=='X' && !vis[p][q+1])
            dfs(board,vis,p,q+1,m,n);
    }
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int c=0;
        vector<vector<bool> > vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='X'){
                    c++;
                    dfs(board,vis,i,j,m,n);
                }
            }
        }
        
        return c;
    }
};
