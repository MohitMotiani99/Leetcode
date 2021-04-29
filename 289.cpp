class Solution {
public:
    int find(int x,int z,int o){
        if(x==1){
            if(o<2 || o>3)
                return 0;
            else 
                return 1;
        }
        else{
            if(o==3)
                return 1;
            else
                return 0;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int arr[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        int r=board.size();
        int c=board[0].size();
        
        //vector<vector<int> > ans(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int cnt=0;
                for(int k=0;k<8;k++){
                    int x=arr[k][0]+i;
                    int y=arr[k][1]+j;
                    if(x>=0 && x<r && y>=0 && y<c)
                        cnt+= (board[x][y]&1);
                }
                if(board[i][j]==0){
                    if(cnt==3)
                        board[i][j]=2;
                }
                else{
                    if(cnt<2 || cnt>3)
                        board[i][j]=1;
                    else
                        board[i][j]=3;
                }
            }
        }
        for(int i=0;i<r;i++)for(int j=0;j<c;j++)board[i][j]>>=1;
    }
};
