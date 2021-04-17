
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int i;
        int c=0;
        
        string str="";
        for(i=0;i<a.size() && i<b.size();i++){
            int x=a[i]-'0';
            int y=b[i]-'0';
            //cout<<x<<y<<c<<endl;
            if(x==0 && y==0 && c==0)
                str+="0",c=0;
            else if((x==1 && y==0 && c==0) || (x==0 && y==1 && c==0) || (x==0 && y==0 && c==1))
                str+="1",c=0;
            else if((x==1 && y==1 && c==0) || (x==1 && y==0 && c==1) || (x==0 && y==1 && c==1))
                str+="0",c=1;
            else
                str+="1",c=1;
        }
        //cout<<str<<endl;
        while(i<a.size()){
            int x=a[i]-'0';
            if(x==1 && c==1)
                str+="0",c=1;
            else if(x==0 && c==0)
                str+="0",c=0;
            else
                str+="1",c=0;
            i++;
        }
        
        while(i<b.size()){
            int x=b[i]-'0';
            if(x==1 && c==1)
                str+="0",c=1;
            else if(x==0 && c==0)
                str+="0",c=0;
            else
                str+="1",c=0;
            i++;
        }
        if(c==1)
            str+="1";
        reverse(str.begin(),str.end());
        return str;
    }
};
