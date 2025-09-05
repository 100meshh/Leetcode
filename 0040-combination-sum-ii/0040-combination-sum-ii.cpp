class Solution {
public:
 void combi(vector<int>& candidates,int index,vector<vector<int>>&ans,vector<int>&temp,int target){
         if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size();i++){
        if(i>index && candidates[i-1]==candidates[i])continue;
          if (candidates[i] > target) break;
        temp.push_back(candidates[i]);
        combi(candidates,i+1,ans,temp,target-candidates[i]);
        temp.pop_back();
        }
        
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        combi(candidates,0,ans,temp,target);
        return ans;
    }
};