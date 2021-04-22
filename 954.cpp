class Solution {
public:
    bool static cmp(int a,int b){
        return abs(a)<abs(b);
    }
    bool canReorderDoubled(vector<int>& arr) {
        
        unordered_map<int,int> m;
        for(auto x:arr)
            m[x]++;
        vector<int> keys;
        for(auto i:m)
            keys.push_back(i.first);
        sort(keys.begin(),keys.end(),cmp);
        for(auto x:keys){
            if(m[x]>m[2*x])
                return false;
            m[2*x]-=m[x];
        }
        return true;
    }
};
