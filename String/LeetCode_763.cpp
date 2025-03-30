/*You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.*/

//Time Complexity -- O(N^2)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n=s.size();

        //output vector
        vector<int>partition;

        //logic  -- take a pointer keep incrementing the pointer up to n-1 when you reach a stage where in the substring every character last occurence in within the same substring , add the length of that substring in the output vector

        //pointer i
        int i=0;

        //for storing the start of the substring
        int start = 0;

        //take another string for calculating the last occurrence
        string temp=s;

        //reverse the string temp
        reverse(temp.begin(),temp.end());

        while(i<n){

            //traverse another array starting from start to i and see if the last occurence of every character stays within the same substring
            bool stays = true;
            for(int index = start;index<=i;index++){
                int last_occurrence = n-1-temp.find(s[index]);
                if(last_occurrence>i){
                    stays=false;
                }
            }
            if(stays==true){
                int length = (i-start)+1;
                partition.push_back(length);
                start=i+1;
            }
            i++;
        }

        //return the output vector
        return partition;
    }
};
