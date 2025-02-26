/*Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 109 + 7.

Example 1:
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.*/

//Brute force approach -- O(n3)
//This won't get accepted

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        //Brute force
        int count=0;
        for(int i=0;i<arr.size()-2;i++){
            for(int j=i+1;j<arr.size()-1;j++){
                for(int k=j+1;k<arr.size();k++){
                    if(arr[i]+arr[j]+arr[k]==target){
                        count=(long long)(count+1)%1000000007;
                    }
                }
            }
        }
        return count;
    }
};
