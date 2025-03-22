/*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

*/

//Time Complexity -- O(32*N)

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int n = nums.size();

        //calculate the number of zeros and ones for all the 32 bits of the elements
        int count=0;
        for(int i=0;i<32;i++){
            int count_0=0;
            int count_1=0;
            bool flag = false;
            for(int j=0;j<n;j++){
                if((nums[j]>>i)>0){
                    flag = true;
                }
                if(((nums[j]>>i)&1)==0){
                    count_0+=1;
                }
                else{
                    count_1+=1;
                }
            }
            if(flag==false){
                break;
            }
            count+=(count_0*count_1); // for every bit , calculate mxn
        }

        //return the count
        return count;
    }
};
