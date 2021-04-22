class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait=0.0;
        double time=customers[0][0];
        for(int i=0;i<customers.size();i++){
            if(time<customers[i][0])
                time=customers[i][0];
            wait+=(time+customers[i][1]-customers[i][0]);
            time=time+customers[i][1];
            
        }
        return wait/((double)customers.size());
    }
};
