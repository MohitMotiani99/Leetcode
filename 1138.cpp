class Solution {
public:
    string alphabetBoardPath(string target) {
        int x=0,y=0;
        string ans="";
        for(int i=0;i<target.size();i++){
            if(i>0 && target[i]==target[i-1])
                ans+="!";
            else{
                if(x==5 && y==5)
                {
                    ans+="U";
                    x--;
                }
                int a,b,rank;
                if(target[i]=='z')
                    rank=20;
                else
                    rank=target[i]-97;
                a=rank/5;
                b=rank%5;
                
                if(x<a){
                    int c=a-x;
                    while(c){
                        ans+="D";
                        c--;
                    }
                }
                else if(x>a){
                    int c=x-a;
                    while(c){
                        ans+="U";
                        c--;
                    }
                }
                
                if(y<b){
                    int c=b-y;
                    while(c){
                        ans+="R";
                        c--;
                    }
                }
                else if(y>b){
                    int c=y-b;
                    while(c){
                        ans+="L";
                        c--;
                    }
                }
                
                if(target[i]=='z')
                {
                    ans+="D";
                    a+=1;
                }
                ans+="!";
                x=a;
                y=b;
                
            }
        }
        return ans;
    }
};
