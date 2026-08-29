class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        string a,b;
        a=endTime.substr(0,2);
        b=startTime.substr(0,2);
        int hr=stoi(a)-stoi(b);
        a=endTime.substr(3,2);
        b=startTime.substr(3,2);
        int min=stoi(a)-stoi(b);
        a=endTime.substr(6,2);
        b=startTime.substr(6,2);
        int sec=stoi(a)-stoi(b);
        return (3600*hr)+(60*min)+sec;
    }
};