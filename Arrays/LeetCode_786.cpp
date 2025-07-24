/*You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].*/

//Time Complexity -- O(n^2log(n^2))

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<double>fractions;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double f = (double)arr[i]/arr[j];
                fractions.push_back(f);
            }
        }
        sort(fractions.begin(),fractions.end());
        double x = fractions[k-1];
        vector<int>answer;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double f = (double)arr[i]/arr[j];
                if(f==x){
                    answer.push_back(arr[i]);
                    answer.push_back(arr[j]);
                    return answer;
                }
            }
        }
        return answer;
    }
};
