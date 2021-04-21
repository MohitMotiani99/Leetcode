class Solution {
public:
    void static nums(string s,vector<string>& v){
        if(s=="0")
        {
            v.push_back("0");
            return;
        }
        if(s[0]=='0' && s[s.size()-1]=='0')
            return;
        if(s[0]=='0'){
            v.push_back("0."+s.substr(1));
            return;
        }
        if(s[s.size()-1]=='0'){
            v.push_back(s);
            return;
        }
        for(int i=0;i<s.size()-1;i++){
            v.push_back(s.substr(0,i+1)+"."+s.substr(i+1));
        }
        v.push_back(s);
        
    }
    vector<string> ambiguousCoordinates(string S) {
        if(S.size()==4)
            return vector<string>{S.substr(0,2)+", "+S.substr(2)};
        set<string> ans;
        for(int i=1;i<S.size()-2;i++){
            string s1=S.substr(1,i);
            string s2=S.substr(i+1,S.size()-i-2);
            vector<string> v1,v2;
            nums(s1,v1);
            nums(s2,v2);
            for(int i=0;i<v1.size();i++){
                for(int j=0;j<v2.size();j++){
                    ans.insert("("+v1[i]+", "+v2[j]+")");
                }
            }
        }
        vector<string> v(ans.begin(),ans.end());
        return v;
    }
};
