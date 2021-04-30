class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // map<int,int> m;
        // for(int i=0;i<nums.size();i++)
        //     m[nums[i]]++;
        // auto it=m.begin();
        // advance(it,k-1);
        // return it->first;
        
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()-k];
        
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<k;i++)
            pq.push(nums[i]);
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
        
        // priority_queue<int> pq(nums.begin(),nums.end());
        // for(int i=0;i<k-1;i++)
        //     pq.pop();
        // return pq.top();
        
        // priority_queue<int,vector<int>,greater<int> > pq(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-k;i++)
        //     pq.pop();
        // return pq.top();
            
        
    }
};
