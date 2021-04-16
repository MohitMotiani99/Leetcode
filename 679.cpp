class Solution {
public:
    bool dfs(vector<double>& tmp){
        if(tmp.size()==1)return (fabs(tmp[0]-24)<1e-8);
        for(int i=0;i+1<tmp.size();i++){
            for(int j=i+1;j<tmp.size();j++){
                vector<double> t;
                for(int k=0;k<tmp.size();k++){
                    if(k!=i && k!=j)
                        t.push_back(tmp[k]);
                }
                
                t.push_back(tmp[i]+tmp[j]);
                if(dfs(t))return true;
                t.back()=tmp[i]-tmp[j];
                if(dfs(t))return true;
                t.back()=tmp[i]*tmp[j];
                if(dfs(t))return true;
                t.back()=tmp[i]/tmp[j];
                if(dfs(t))return true;
                t.back()=tmp[j]-tmp[i];
                if(dfs(t))return true;
                t.back()=tmp[j]/tmp[i];
                if(dfs(t))return true;
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& nums) {
        vector<double> tmp(nums.begin(),nums.end());
        //sort(nums.begin(),nums.end());
        return dfs(tmp);
    }
};
