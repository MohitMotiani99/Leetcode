class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        //s.push(a[0]);
        for(int i=0;i<a.size();i++){
            if(s.size()==0)
                s.push(a[i]);
            else if(a[i]>0 && s.top()<0)
                s.push(a[i]);
            else if(a[i]*s.top()>0)
                s.push(a[i]);
            else{
                int e=0;
                while(!s.empty() && s.top()>0 && a[i]<0){
                    if(abs(s.top())>abs(a[i]))
                        break;
                     else if(abs(s.top())==abs(a[i])){
                         e=1;
                         s.pop();
                         break;
                     }
                    else if(!s.empty())
                        s.pop();
                    else
                        break;
                }
                //if(e==0){
                if(e==1){}
                else if(s.empty() || s.top()<0)
                    s.push(a[i]);
                //}
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
