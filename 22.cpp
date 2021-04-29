class Solution {
public:
    void par(vector<string>& ans,string str,int l,int r){
        if(l==0 && r==0){
            ans.push_back(str);
            return ;
        }
        if(l>0)par(ans,str+"(",l-1,r);
        if(r>l)par(ans,str+')',l,r-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        par(ans,"",n,n);
        return ans;
    }
};
