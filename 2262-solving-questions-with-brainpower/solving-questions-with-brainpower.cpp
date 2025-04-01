class Solution {

    long long findMax(vector<vector<int>>& questions,int index, vector<long long>&mem)   //mem stands for memoization
    {
        if(index>=questions.size()) return 0;
        if(mem[index]!=-1) return mem[index];

        long long notInclude =findMax(questions,index+1,mem);
        long long Include =questions[index][0]+findMax(questions,index+questions[index][1]+1,mem);

        return mem[index] = max(notInclude,Include);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>mem(n,-1);
        return findMax(questions,0,mem);    
    }
};