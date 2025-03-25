class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Build candidate arrays from unique boundaries for x and y.
        // For vertical cuts we use x-coordinates; for horizontal, y-coordinates.
        set<int> xSet, ySet;
        for (auto &rect : rectangles) {
            xSet.insert(rect[0]); xSet.insert(rect[2]);
            ySet.insert(rect[1]); ySet.insert(rect[3]);
        }
        vector<int> xCand(xSet.begin(), xSet.end());
        vector<int> yCand(ySet.begin(), ySet.end());
        return checkOrientation(rectangles, xCand, true) || checkOrientation(rectangles, yCand, false);
    }
    
private:
    // Check if there exists a valid pair of cuts along the candidate coordinates
    // 'isVertical' indicates whether we are processing x-coordinates (vertical cuts)
    // or y-coordinates (horizontal cuts).
    bool checkOrientation(const vector<vector<int>>& rectangles, const vector<int>& cand, bool isVertical) {
        int m = cand.size();
        int R = rectangles.size();
        
        // Map each rectangle's boundaries to candidate indices.
        // For vertical: Lidx = index of rect[0], Ridx = index of rect[2].
        // For horizontal: Lidx = index of rect[1], Ridx = index of rect[3].
        vector<int> Lidx(R), Ridx(R);
        for (int i = 0; i < R; i++){
            int leftCoord  = isVertical ? rectangles[i][0] : rectangles[i][1];
            int rightCoord = isVertical ? rectangles[i][2] : rectangles[i][3];
            int li = lower_bound(cand.begin(), cand.end(), leftCoord) - cand.begin();
            int ri = lower_bound(cand.begin(), cand.end(), rightCoord) - cand.begin();
            Lidx[i] = li;
            Ridx[i] = ri;
        }
        
        // Build frequency arrays:
        // freqRight[k] counts rectangles whose right boundary is at candidate index k.
        // freqLeft[k] counts rectangles whose left boundary is at candidate index k.
        vector<int> freqRight(m, 0), freqLeft(m, 0);
        for (int i = 0; i < R; i++){
            freqRight[Ridx[i]]++;
            freqLeft[Lidx[i]]++;
        }
        
        // prefix[k]: number of rectangles with Ridx <= k.
        vector<int> prefix(m, 0);
        prefix[0] = freqRight[0];
        for (int i = 1; i < m; i++){
            prefix[i] = prefix[i-1] + freqRight[i];
        }
        
        // suffix[k]: number of rectangles with Lidx >= k.
        vector<int> suffix(m, 0);
        suffix[m-1] = freqLeft[m-1];
        for (int i = m-2; i >= 0; i--){
            suffix[i] = suffix[i+1] + freqLeft[i];
        }
        
        // For a candidate left cut at candidate[i], every rectangle with Lidx < i must have Ridx <= i.
        // Compute maxRPrefix[i] = maximum Ridx among rectangles with Lidx < i.
        vector<int> maxAtL(m, -1);
        for (int i = 0; i < R; i++){
            int li = Lidx[i], ri = Ridx[i];
            maxAtL[li] = max(maxAtL[li], ri);
        }
        vector<int> maxRPrefix(m, -1);
        maxRPrefix[0] = -1;
        for (int i = 1; i < m; i++){
            maxRPrefix[i] = max(maxRPrefix[i-1], maxAtL[i-1]);
        }
        
        // For a candidate right cut at candidate[j], every rectangle with Ridx > j must have Lidx >= j.
        // Compute minLSuffix[j] = minimum Lidx among rectangles with Ridx > j.
        vector<int> minAtR(m, m);
        for (int i = 0; i < R; i++){
            int ri = Ridx[i], li = Lidx[i];
            minAtR[ri] = min(minAtR[ri], li);
        }
        vector<int> minLSuffix(m, m);
        minLSuffix[m-1] = m; // no rectangle with Ridx > last candidate.
        for (int j = m-2; j >= 0; j--){
            minLSuffix[j] = min(minLSuffix[j+1], minAtR[j+1]);
        }
        
        // Now, iterate over candidate pairs (i, j) with i < j.
        // Use candidate[i] as left cut and candidate[j] as right cut.
        for (int i = 0; i < m - 1; i++){
            // The left cut is valid only if every rectangle with Lidx < i ends by candidate[i].
            if (maxRPrefix[i] > i) continue;
            if (prefix[i] == 0) continue; // no rectangle is completely to the left.
            for (int j = i + 1; j < m; j++){
                // The right cut is valid only if every rectangle with Ridx > j starts at or after candidate[j].
                if (minLSuffix[j] < j) continue;
                if (suffix[j] == 0) continue; // no rectangle is completely to the right.
                int midCount = R - prefix[i] - suffix[j];
                if (midCount <= 0) continue; // middle section empty.
                // If we reach here, every rectangle falls into one of the three sections:
                //   left: Ridx <= i, middle: (Lidx >= i and Ridx <= j), right: Lidx >= j.
                return true;
            }
        }
        return false;
    }
};
