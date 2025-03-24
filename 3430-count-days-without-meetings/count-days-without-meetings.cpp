class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Step 1: Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Step 2: Merge overlapping meetings
        int freeDays = 0;
        int lastEnd = 0; // Track the end of the last merged meeting

        for (auto &m : meetings) {
            int start = m[0], end = m[1];

            // Count free days between last meeting and current meeting
            if (start > lastEnd + 1) {  
                freeDays += (start - lastEnd - 1);
            }

            // Update lastEnd to the max end encountered
            lastEnd = max(lastEnd, end);
        }

        // Step 3: Count free days after the last meeting
        if (lastEnd < days) {
            freeDays += (days - lastEnd);
        }

        return freeDays;
    }
};