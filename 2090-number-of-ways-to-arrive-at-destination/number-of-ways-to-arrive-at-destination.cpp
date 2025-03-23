class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }
        
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0);
        
        while (!pq.empty()) {
            auto [curDist, node] = pq.top(); pq.pop();
            
            if (curDist > dist[node]) continue;
            
            for (auto& [neighbor, time] : graph[node]) {
                long long newDist = curDist + time;
                
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    pq.emplace(newDist, neighbor);
                } else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};