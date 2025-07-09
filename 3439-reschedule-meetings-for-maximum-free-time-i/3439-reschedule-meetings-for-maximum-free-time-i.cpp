class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>gaps;
        gaps.push_back(startTime[0]);
        int n=startTime.size();
        for(int i=1;i<n;i++){
            gaps.push_back(startTime[i]-endTime[i-1]);
        }
        gaps.push_back(eventTime-endTime[n-1]);
        int maxcurrent=0;
        for(int i=0;i<k+1;i++){
            maxcurrent+=gaps[i];
        }
        int maxgap=maxcurrent;
        for(int i=k+1;i<gaps.size();i++){
            maxcurrent+=gaps[i]-gaps[i-(k+1)];
            maxgap=max(maxgap,maxcurrent);
        }
        return maxgap;
        
    }
};