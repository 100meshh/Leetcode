class Solution {
public:
    void combi(vector<int>& candidates,int index,vector<vector<int>>&ans,vector<int>&temp,int target){
        if (target < 0) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(index==candidates.size())return;
        
        //not pick
        combi(candidates,index+1,ans,temp,target);
        //pick
        temp.push_back(candidates[index]);
        combi(candidates,index,ans,temp,target-candidates[index]);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        combi(candidates,0,ans,temp,target);
        return ans;
    }
};