class Solution {
public:
    double average(vector<int>& salary) {
        int sum=0;
        sum=accumulate(salary.begin(),salary.end(),sum);
        return (sum-*max_element(salary.begin(),salary.end())-*min_element(salary.begin(),salary.end()))/((double)(salary.size()-2));
    }
};
