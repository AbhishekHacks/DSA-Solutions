/*You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:

Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.
Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.

*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int n = nums.size();
        int operations=0;

        int i=0;
        while((3*i)<n){
            unordered_map<int,int>m;
            for(int j=(3*i);j<n;j++){
                if(m.count(nums[j])){
                    operations+=1;
                    break;
                }
                else{
                    m[nums[j]]++;
                }
            }
            i++;
        }

        return operations;
    }
};
