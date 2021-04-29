class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n=gas.size();
//         if(n==1){
//             if(gas[0]>=cost[0])
//                 return 0;
//             else
//                 return -1;
//         }
//         for(int i=0;i<n;i++){
//             int j=i;
//             int g=0;
//             if(g+gas[j]>=cost[j]){
//                 g=g+gas[j]-cost[j];
//                 j=(j+1)%n;
//             }
//             if(j!=i){
//                 while(g+gas[j]>=cost[j] && j!=i){
//                     g=g+gas[j]-cost[j];
//                     j=(j+1)%n;
//                 }
//                 if(j==i)
//                     return j;
//                 else if(j>i)
//                     i=j;
                     
//             }
//             else
//                 i=j;
//         }
//         return -1;
        
        int n=gas.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=gas[i]-cost[i];
        if(sum<0)
            return -1;
        sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(sum<0)
                ans=i,sum=0;
            sum+=gas[i]-cost[i];
        }
        return ans;
    }
};
