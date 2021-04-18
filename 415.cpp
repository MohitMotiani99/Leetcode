class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string str="";
        
        int c=0;
        int i;
        for(i=0;i<min(num1.size(),num2.size());i++){
            int x=num1[i]-'0';
            int y=num2[i]-'0';
            
            str+=((x+y+c)%10 + '0');
            c=(x+y+c)/10;
        }
        while(i<num1.size()){
            int x=num1[i]-'0';
            //int y=num2[i]-'0';
            
            str+=((x+c)%10 + '0');
            c=(x+c)/10;
            i++;
        }
        while(i<num2.size()){
            int x=num2[i]-'0';
            //int y=num2[i]-'0';
            
            str+=((x+c)%10 + '0');
            c=(x+c)/10;
            i++;
        }
        if(c!=0)
            str+=(c+'0');
        reverse(str.begin(),str.end());
        
        return str;
    }
};
