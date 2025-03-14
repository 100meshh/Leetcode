class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans; 
        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "C")
            {
                if (!ans.empty())
                ans.pop_back(); // Remove last valid score
            } 
            else if (operations[i] == "D") 
            {
                if (!ans.empty()) 
                ans.push_back(2 * ans.back());
            } 
            else if (operations[i] == "+") 
            {
                if (ans.size() >= 2)
                {
                    ans.push_back(ans[ans.size() - 1] + ans[ans.size() - 2]);
                }
            } 
            else {
                ans.push_back(stoi(operations[i])); // stoi- Convert string to integer and add to record
            }
        }

        int sum = 0;
        for (int i = 0; i < ans.size(); i++) {
            sum += ans[i]; // Compute the total sum
        }
        return sum;
    }
};