class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int P) {
        int n=t.size();
        int score=0,ans=0;
        sort(t.begin(),t.end());
        int i=0,j=n-1;
        if(n==0)
            return 0;
        if(n==1 && P<t[0])
            return 0;
        while(i<=j){
            if(t[i]<=P){
                P-=t[i];
                score++;
                ans=max(ans,score);
                i++;
            }
            else if(score>0){
                P+=t[j];
                j--;
                score--;
            }
            else
                break;
        }
        
        return ans;
        
    }
};
