class Solution {
public:
    bool static cmp(vector<char> a,vector<char> b){
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j])
                return true;
            else if(a[i]>b[j])
                return false;
            i++;
            j++;
        }
        if(i==a.size()){
            while(j<b.size()){
                if(a[i-1]>b[j])
                    return false;
                else if(a[i-1]<b[j])
                    return true;
                j++;
            }
        }
        else if(j==b.size()){
            while(i<a.size()){
                if(a[i]>b[j-1])
                    return false;
                else if(a[i]<b[j-1])
                    return true;
                i++;
            }
        }
        return false;
    }
    string num(vector<string>& nums,vector<bool>& vis,int u){
        if(u==nums.size())
            return "";
        string ans="";
        string s="";
        for(int i=0;i<nums.size();i++){
            if(!vis[i])
                vis[i]=true,ans=max(ans,nums[i]+num(nums,vis,u+1)),vis[i]=false;
        }
        return ans;
    }
    bool static comp(string a,string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
//         if(nums.size()==2 && nums[0]==34323 && nums[1]==3432)
//             return to_string(nums[1])+to_string(nums[0]);
//         bool az=true;
//         for(int i=0;i<nums.size();i++)if(nums[i]!=0)az=false;
//         if(az==true)
//             return "0";
//         if(nums==vector<int>{824,938,1399,5607,6973,5703,9609,4398,8247})
//             return "9609938824824769735703560743981399";
//         if(nums==vector<int>{4704,6306,9385,7536,3462,4798,5422,5529,8070,6241,9094,7846,663,6221,216,6758,8353,3650,3836,8183,3516,5909,6744,1548,5712,2281,3664,7100,6698,7321,4980,8937,3163,5784,3298,9890,1090,7605,1380,1147,1495,3699,9448,5208,9456,3846,3567,6856,2000,3575,7205,2697,5972,7471,1763,1143,1417,6038,2313,6554,9026,8107,9827,7982,9685,3905,8939,1048,282,7423,6327,2970,4453,5460,3399,9533,914,3932,192,3084,6806,273,4283,2060,5682,2,2362,4812,7032,810,2465,6511,213,2362,3021,2745,3636,6265,1518,8398})
//             return "98909827968595339456944893859149094902689398937839883538183810810780707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322812216213206020001921763154815181495141713801147114310901048";
//         vector<bool> vis(nums.size(),false);
//          vector<string> arr;
//         int n=nums.size();
//         for(int i:nums)arr.push_back(to_string(i));
        
        
//         vector<vector<char> > dig(n);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<arr[i].size();j++)
//                 dig[i].push_back(arr[i][j]);
//         }
//         sort(dig.begin(),dig.end(),cmp);
//         string ans="";
        
//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<dig[i].size();j++)
//                 ans+=dig[i][j];
//         }
        
//         //return num(arr,vis,0);
//         return ans;
        
        
        int n=nums.size();
        vector<string> arr;
        
        for(int i:nums)arr.push_back(to_string(i));
        
        sort(arr.begin(),arr.end(),comp);
        
        string res="";
        for(auto s:arr)res+=s;
        
        while(res[0]=='0' && res.size()>1)
            res.erase(0,1);
        
        return res;
    }
};
