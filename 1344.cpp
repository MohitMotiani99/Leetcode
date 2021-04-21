class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h=hour;
        double m=minutes;
        if(h==12)
            h=0;
        double total=h*60+m;
        double ha=total*0.5;
        double ma=m*6;
        return min(abs(ha-ma),360-abs(ha-ma));
    }
};
