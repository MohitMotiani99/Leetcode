class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        int c=0;
        for(int i=n-1;i>=0;i--){
            
                int x=num[i];
                num[i]=(x+k%10+c)%10;
                c=(c+k%10+x)/10;
                k=k/10;
            
        }
        cout<<c<<endl;
        while(k!=0){
            num.insert(num.begin(),(c+k%10)%10);
            c=(c+k%10)/10;
            k/=10;
        }
        if(c)
            num.insert(num.begin(),c);
        return num;
    }
};
