class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//         int target=0;
//         int n=A.size();
//         sort(A.begin(),A.end());
//         sort(B.begin(),B.end());
//         sort(C.begin(),C.end());
//         sort(D.begin(),D.end());
        
//         int cnt=0;
        
//         for(int i=0;i<n;i++){
//             if(A[i]+B[n-1]+C[n-1]+D[n-1]<0)continue;
//             if(A[i]+B[0]+C[0]+D[0]>0)break;
            
//             for(int j=0;j<n;j++){
//                 if(A[i]+B[j]+C[n-1]+D[n-1]<0)continue;
//                 if(A[i]+B[j]+C[0]+D[0]>0)break;
                
//                 for(int k=0;k<n;k++){
                    
                    
//                     if(A[i]+B[j]+C[k]+D[n-1]<0)continue;
//                     if(A[i]+B[j]+C[k]+D[0]>0)break;
                    
//                     if(binary_search(D.begin(),D.end(),0-A[i]-B[j]-C[k]))
//                         cnt++;
//                 }
//             }
//         }
//         return cnt;
        
        unordered_map<int,int> m;
        int n=A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[A[i]+B[j]]++;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cnt+=(m[0-C[i]-D[j]]);
            }
        }
        return cnt;
    }
};
