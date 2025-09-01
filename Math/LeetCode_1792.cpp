/*There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.*/

//Time Complexity -- O(Nlogn + Mlogn)

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        vector<double>pass_ratio;
        multimap<double,int>differences;
        for(int i=0;i<n;i++){
            pass_ratio.push_back((double)classes[i][0]/classes[i][1]);
            double x = ((double)classes[i][0]+1)/(classes[i][1]+1);
            double diff = x - pass_ratio[i];
            differences.insert({diff,i});
        }
        while(extraStudents>0){
            auto it = prev(differences.end());
            int index = it->second;
            classes[index][0] = classes[index][0]+1;
            classes[index][1] = classes[index][1]+1;
            pass_ratio[index]=((double)classes[index][0]/classes[index][1]);
            differences.erase(it);
            double x = ((double)classes[index][0]+1)/(classes[index][1]+1);
            double diff = x - pass_ratio[index];
            differences.insert({diff,index});
            extraStudents--;
        }
        double sum = accumulate(pass_ratio.begin(),pass_ratio.end(),0.0);
        return sum/n;
    }
};
