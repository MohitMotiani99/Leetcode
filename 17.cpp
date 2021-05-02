class Solution {
public:
    void lc(string digits,vector<string>& ans,int ind,string arr[]){
        if(ind==digits.size())
        {
            ans.push_back("");
            return;
        }
        vector<string> so;
        lc(digits,so,ind+1,arr);
        for(int i=0;i<so.size();i++){
            string x=arr[digits[ind]-'0'];
            for(int j=0;j<x.size();j++)
                ans.push_back(x[j]+so[i]);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        string arr[10];
        arr[2]="abc";
        arr[3]="def";
        arr[4]="ghi";
        arr[5]="jkl";
        arr[6]="mno";
        arr[7]="pqrs";
        arr[8]="tuv";
        arr[9]="wxyz";
        if(digits=="")
            return {};
        vector<string> ans;
        lc(digits,ans,0,arr);
        return ans;
    }
};
