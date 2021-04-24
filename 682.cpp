class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> s;
        for(int i=0;i<ops.size();i++){
            int n=s.size();
            if(ops[i]=="+")
                s.push_back(s[n-1]+s[n-2]);
            else if(ops[i]=="D")
                s.push_back(2*s[n-1]);
            else if(ops[i]=="C")
                s.pop_back();
            else
                s.push_back(stoi(ops[i]));
        }
        int sum=0;
        return accumulate(s.begin(),s.end(),sum);
    }
};
