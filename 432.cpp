class AllOne {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> m;
    AllOne() {
            
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        m[key]++;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m[key]==1)
            m.erase(key);
        else
            m[key]--;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(m.size()==0)
            return "";
        int maxi=-1;
        string ans;
        for(auto i:m){
            if(maxi<i.second)
                maxi=i.second,ans=i.first;
        }
        return ans;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(m.size()==0)
            return "";
        int mini=INT_MAX;
        string ans;
        for(auto i:m){
            if(mini>i.second)
                mini=i.second,ans=i.first;
        }
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
