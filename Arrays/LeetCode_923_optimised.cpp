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

//Time Complexity -- O(n2)

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        //optimise--O(n2)
        int count=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-2;i++){
            int left = i+1;
            int right = arr.size()-1;
            while(left<right){
                int sum = arr[i]+arr[left]+arr[right];
                if(sum==target){
                    if(arr[left]==arr[right]){
                        int n = (right-left)+1;
                        count=(long long)(count+(n*(n-1))/2)%1000000007;
                        break;
                    }
                    else{
                        int leftCount=1;
                        int rightCount=1;
                        while(left+1<right&&arr[left]==arr[left+1]){
                            leftCount++;
                            left++;
                        }
                        while(right-1>left&&arr[right]==arr[right-1]){
                            rightCount++;
                            right--;
                        }
                        int temp = leftCount*rightCount;
                        count=(long long)(count+temp)%1000000007;
                    }
                    left++;
                    right--;
                }
                else if(sum>target){
                    right--;
                }
                else{
                    left++;
                }
            }
        } 
        return count;   
    }
};
