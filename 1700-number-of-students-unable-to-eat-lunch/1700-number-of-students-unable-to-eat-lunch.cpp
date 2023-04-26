class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count = 0;
        while(true){
            if(students[0]==sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                count=0;
            }

            else{
                students.push_back(students[0]);
                students.erase(students.begin());
                count++;
            }

            if(students.size() == 0){
                return 0;
            }

            if(count == students.size()){
                break;
            }
        }
        
        return count;
    }
};