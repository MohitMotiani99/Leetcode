class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if(numerator==0)return "0";
        
        string res="";
        if(numerator<0 ^ denominator<0)res+="-";
        numerator=abs(numerator);
        denominator=abs(denominator);
        res+=to_string(numerator/denominator);
        
        if(numerator%denominator==0)return res;
        
        res+='.';
        
        unordered_map<int,int> m;
        long long r;
        for(r=numerator%denominator;r;r%=denominator){
            if(m.find(r)!=m.end()){
                res.insert(m[r],"(");
                res+=")";
                break;
            }
            
            m[r]=res.size();
            r*=10;
            res+=to_string(r/denominator);
        }
        return res;
    }
};
