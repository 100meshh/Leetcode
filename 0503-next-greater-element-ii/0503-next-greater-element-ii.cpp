class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>res(n,-1);
        for(int i=0;i<2*n;i++){
            int num=nums[i%n];      //circular array soln

            //logic
            while(!st.empty() && nums[st.top()]<num){
                res[st.top()]=num;
                st.pop();
            }

            //push only original size
            if(i<n)st.push(i);
        }
        return res;
    }
};