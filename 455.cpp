class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int m=g.size(),n=s.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(s[j]>=g[i])
                cnt++,i++,j++;
            else
                j++;
        }
        return cnt;
    }
};
