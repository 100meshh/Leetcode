class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = 0;
        float slowest = 0;
        vector<pair<int,int>> cars;  // don't use name "map"

        for (int i = 0; i < position.size(); i++) {
            cars.push_back(make_pair(position[i], speed[i]));
        }

        // sort by position (descending)
        sort(cars.begin(), cars.end());
        reverse(cars.begin(), cars.end());

        for (int i = 0; i < cars.size(); i++) {
            float time = (float)(target - cars[i].first) / (float)(cars[i].second);
            if (time > slowest) {
                ans++;
                slowest = time;
            }
        }
        return ans;
    }
};
