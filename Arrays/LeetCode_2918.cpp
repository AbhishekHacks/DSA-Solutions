/*You are given two arrays nums1 and nums2 consisting of positive integers.

You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.

Return the minimum equal sum you can obtain, or -1 if it is impossible.

 */

//Time Complexity -- O(n)

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        long long sum1 = 0;
        long long sum2 = 0;
        int count_0_1=0;
        int count_0_2=0;
        
        for(int i=0;i<n;i++){
            if(nums1[i]==0){
                count_0_1+=1;
            }
            sum1+=nums1[i];
        }
        for(int i=0;i<m;i++){
            if(nums2[i]==0){
                count_0_2+=1;
            }
            sum2+=nums2[i];
        }

        //base case -- if there are no zeros 
        if(count_0_1==0&&count_0_2==0){
            if(sum1==sum2){
                return sum1;
            }
            else{
                return -1;
            }
        }
        //base case -- if no zero in 1
        if(count_0_1==0){
            if(sum1<=sum2){
                return -1;
            }
            else{
                sum2=sum2+count_0_2;
                if(sum1<sum2){
                    return -1;
                }
                else{
                    return sum1;
                }
            }
        }
        //base case -- if no 0 in 2
        if(count_0_2==0){
            if(sum1>=sum2){
                return -1;
            }
            else{
                sum1=sum1+count_0_1;
                if(sum1>sum2){
                    return -1;
                }
                else{
                    return sum2;
                }
            }
        }
        long long totalsum1 = sum1+count_0_1;
        long long totalsum2 = sum2+count_0_2;
        return max(totalsum1,totalsum2);
    }
};
