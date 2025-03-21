/*There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.*/

//Time Complexity -- O(N)

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        int count=0;
        for(int i=0;i<answers.size();i++){
            if(answers[i]==0){
                count+=1;
            }
            else if(m.count(answers[i])==0){
                count+=(answers[i]+1);
                m[answers[i]]=answers[i];
            }
            else{
                m[answers[i]]--;
                if(m[answers[i]]==0){
                    m.erase(answers[i]);
                }
            }
        }
        return count;
    }
};
