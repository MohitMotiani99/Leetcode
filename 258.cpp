class Solution {
public:
    int addDigits(int num) {
        
        long long sum=0;
        while(num/10!=0){
            sum=0;
            while(num!=0){
                sum+=(num%10);
                num/=10;
                
            }
            num=sum;
        }
        return num;
        
//         string str=to_string(num);
//         int sum=0;
//         while(str.size()>1){
            
//         }
    }
};
