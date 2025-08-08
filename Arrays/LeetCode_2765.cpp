/*You are given a 0-indexed integer array nums. A subarray s of length m is called alternating if:

m is greater than 1.
s1 = s0 + 1.
The 0-indexed subarray s looks like [s0, s1, s0, s1,...,s(m-1) % 2]. In other words, s1 - s0 = 1, s2 - s1 = -1, s3 - s2 = 1, s4 - s3 = -1, and so on up to s[m - 1] - s[m - 2] = (-1)m.
Return the maximum length of all alternating subarrays present in nums or -1 if no such subarray exists.

A subarray is a contiguous non-empty sequence of elements within an array.*/

//Time Complexity -- O(n^3)

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int maximum = -1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int>temp;
                for(int k=i;k<=j;k++){
                    temp.push_back(nums[k]);
                }
                int len = temp.size();
                bool negative = false;
                bool positive = false;
                bool valid = true;
                for(int k=1;k<len;k++){
                    if(!negative&&!positive){
                        if(temp[k]-temp[k-1]==1){
                            positive = true;
                        }
                        else{
                            valid=false;
                            break;
                        }
                    }
                    else if(negative){
                        if(temp[k]-temp[k-1]==1){
                            negative=false;
                            positive=true;
                        }
                        else{
                            valid=false;
                            break;
                        }
                    }
                    else if(positive){
                        if(temp[k]-temp[k-1]==-1){
                            positive=false;
                            negative=true;
                        }
                        else{
                            valid=false;
                            break;
                        }
                    }
                }
                if(valid){
                    maximum = max(maximum,len);
                }
            }
        }
        return maximum;
    }
};
