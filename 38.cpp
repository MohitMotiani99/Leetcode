class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        int c=1;
        while(c<n){
            string str="";
            int cnt=1;
            char ch=ans[0];
            for(int i=1;i<ans.size();i++){
                if(ans[i]==ans[i-1])
                    cnt++;
                else{
                    str+=(cnt+'0');
                    str+=ch;
                    cnt=1;
                    ch=ans[i];
                }
            }
            str+=(cnt+'0');
            str+=ch;
            // cnt=1;
            // ch=ans[i];
            c++;
            ans=str;
        }
        return ans;
    }
};
