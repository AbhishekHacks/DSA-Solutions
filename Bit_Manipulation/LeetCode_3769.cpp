/*You are given an integer array nums.

The binary reflection of a positive integer is defined as the number obtained by reversing the order of its binary digits (ignoring any leading zeros) and interpreting the resulting binary number as a decimal.

Sort the array in ascending order based on the binary reflection of each element. If two different numbers have the same binary reflection, the smaller original number should appear first.

Return the resulting sorted array.*/

//Time Complexity -- O(nlogn)

class Solution {
public:

    int reverse_number(int number){
        int count = -1;
        int num = number;
        while(number>0){
            count++;
            number=number>>1;
        }
        int ans = 0;
        while(num>0){
            int r = (num&1);
            if(r==1){
                ans+=pow(2,count);   
            }
            count--;
            num=num>>1;
        }
        return ans;
    }
    
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>pair_num;
        for(int i=0;i<n;i++){
            int number = nums[i];
            vector<int>temp;
            temp.push_back(number);
            temp.push_back(reverse_number(number));
            pair_num.push_back(temp);
        }
        sort(pair_num.begin(),pair_num.end(),[](const vector<int>&a,vector<int>&b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return a[1]<b[1];
        });
        int len = pair_num.size();
        vector<int>output;
        for(int i=0;i<len;i++){
            output.push_back(pair_num[i][0]);
        }
        return output;
    }
};
