/*Given an array arr[] of positive integers and an integer k. You have to find the maximum value for each contiguous subarray of size k. Return an array of maximum values corresponding to each contiguous subarray.*/

//Time Complexity -- O(nlogn)

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int>answer;
        map<int,int>m;
        for(int i=0;i<k;i++){
            m[arr[i]]++;
        }
        auto it = m.end();
        it--;
        int maximum = it->first;
        answer.push_back(maximum);
        int index = 0;
        for(int i=k;i<n;i++){
            m[arr[i]]++;
            m[arr[index]]--;
            if(m[arr[index]]==0){
                m.erase(arr[index]);
            }
            auto temp_it = m.end();
            temp_it--;
            int temp = temp_it->first;
            answer.push_back(temp);
            index++;
        }
        return answer;
    }
};
