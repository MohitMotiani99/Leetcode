class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
//         int ans=0;
//         int mod=pow(10,9)+7;
//         sort(arr.begin(),arr.end());
//         int n=arr.size();
        
//         for(int i=0;i<n-2;i++){
            
//              // if(i>0 && arr[i]==arr[i-1]){
//              //     ans=(ans*2)%mod;
//              //     continue;
//              // }
//             if(arr[i]+arr[i+1]+arr[i+2]>target)break;
//             if(arr[i]+arr[n-2]+arr[n-1]<target)continue;
            
//             int l=i+1,r=n-1;
//             while(l<r){
//                 int s=arr[i]+arr[l]+arr[r];
//                 if(s<target)
//                     l++;
//                 else if(s>target)
//                     r--;
//                 else if(arr[l]!=arr[r]){
//                     //cout<<i<<" "<<l<<" "<<r<<" ";
//                     int cnt1=1,cnt2=1;
//                     while(l+1<r && arr[l]==arr[l+1]){
//                         cnt1++;
//                         l++;
//                     }
//                     while(r-1>l && arr[r]==arr[r-1]){
//                         cnt2++;
//                         r--;
//                     }
                                    
                    
                    
//                     ans=(ans+((cnt1%mod) * (cnt2%mod))%mod)%mod;
                    
//                     l++;
//                     r--;
                    
//                     cout<<ans<<endl;
                     
//                 }
//                 else{
//                     ans+=(((r-l+1)*(r-l))/2);
//                     ans%=mod;
//                     break;
//                 }
//             }
            
//         }
//         return ans;
        
        
        int dp[101];
        int mod=pow(10,9)+7;

        int n=arr.size();
        for(int i=0;i<101;i++)dp[i]=0;
        for(int i=0;i<n;i++)
            dp[arr[i]]++;
        
        long long ans=0;
        for(int i=0;i<101;i++){
            if(dp[i]==0)continue;
            for(int j=0;j<101;j++){
                    if(dp[j]==0 )continue;
                    int k=target-i-j;
                    
                    if(k<0 || k>100 || dp[k]==0)continue;
                        if(i==j && j==k){
                            long long int x=dp[i];
                            if(x>=3)
                                ans=(ans+((x*(x-1)*(x-2))/6))%mod;
                        }      
                        else if(i==j && j!=k){
                            long long int x=dp[i];
                            if(x>=2)
                                ans=(ans+((x*(x-1)*dp[k])/2))%mod;
                        }
                        // else if(i==k && j!=k){
                        //     int x=dp[i];
                        //     if(x>=2)
                        //         ans=(ans+((x*(x-1)*dp[j])/2))%mod;
                        // }
                        // else if(k==j && i!=k){
                        //     int x=dp[k];
                        //     if(x>=2)
                        //         ans=(ans+((x*(x-1)*dp[i])/2))%mod;
                        // }
                        else if(i<j && j<k)
                            ans=(ans+dp[i]*dp[j]*dp[k])%mod;
                    
                
            }
        }
        return ans;
    }
};
