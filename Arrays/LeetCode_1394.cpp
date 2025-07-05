/*Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.*/

//Time Complexity -- O(n)

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i :arr){
            m[i]++;
        }
        int maximum = -1;
        for(auto i:m){
            if(i.first==i.second){
                maximum = max(maximum,i.first);
            }
        }
        return maximum;
    }
};
