/*Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.*/

//Time Complexity -- O()

//This is the optimal solution

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //Optimal solution -- O(nlogn)
        vector<int> v;
        for(int i=0;i<numbers.size()-1;i++){
            int key = target - numbers[i];
            int start=i+1;
            int end=numbers.size()-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(numbers[mid]==key){
                    v.push_back(i+1);
                    v.push_back(mid+1);
                    break;
                }
                else if(numbers[mid]>key){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            if(v.size()!=0){
                break;
            }
        }
        return v;
    }
};
