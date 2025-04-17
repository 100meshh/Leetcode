class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int student_count=students.size();
        int count0stu=0;
        int count1stu=0;
        for(int i=0;i<students.size();++i)
        {
            if(students[i]==0) count0stu++;
            else{
            count1stu++;
            }
        }
        for(int i=0;i<sandwiches.size();++i)
        {
            if(sandwiches[i]==0){
                if(count0stu>0) {
                    count0stu--;
                    student_count--;
                }
                else
                return student_count;
            }
            else{
                if(count1stu>0) {
                    count1stu--;
                    student_count--;
                }
                else
                return student_count;
            }
        }
        return 0;
    }
};