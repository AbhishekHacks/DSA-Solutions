/*Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.*/

//Time Complexity -- O(n)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        //base case -- when the array contains all 1s and no zeros
        bool iszero=false;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                iszero=true;
                break;
            }
        }
        if(!iszero){
            return n-1;
        }

        //base case -- when the array contains all zeros and no 1s
        bool isone=false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                isone=true;
                break;
            }
        }
        if(!isone){
            return 0;
        }

        //two pointer approach
        vector<int>output;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0&&count==0){
                output.push_back(0);
            }
            else if(nums[i]==0&&count>0){
                output.push_back(count);
                count=0;
                i--;
            }
            else{
                count+=1;
            }
        }
        if(count>0){
            output.push_back(count);
        }
        int s = output.size();
        int i=-1;
        int maximum=1;
        for(int j=0;j<s;j++){
            if(output[j]!=0){
                if(i==-1){
                    i=j;
                }
                else{
                    if(j-i==2){
                        int sum=output[i]+output[j];
                        maximum = max(maximum,sum);
                    }
                    i=j;
                }
                maximum=max(maximum,output[j]);
            }
        }

        return maximum;
    }
};
