class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > m;
        for(int i=0;i<strs.size();i++){
            int arr[26]={0};
            for(int j=0;j<strs[i].size();j++)
                arr[strs[i][j]-'a']++;
            string s="";
            for(int j=0;j<26;j++)
                s+=(arr[j]+'0');
            m[s].push_back(strs[i]);
            
        }
        vector<vector<string> > ans;
        for(auto i:m)
            ans.push_back(i.second);
        
        return ans;
    }
};
