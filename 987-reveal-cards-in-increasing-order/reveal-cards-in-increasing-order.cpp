class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>ans(n);
        queue<int>q;
        sort(deck.begin(),deck.end());
        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        int i=0;
        while(!q.empty()){
            int k = q.front();
            ans[k]=deck[i];
            q.pop();
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
            i++;
        }
        return ans;
    }
};