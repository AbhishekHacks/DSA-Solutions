/*You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.*/

//Time Complexity -- O(log10(n))

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int num = 1;
        vector<int>nums;
        while(num<=1000000000){
            nums.push_back(num);
            num*=2;
        }
        unordered_map<int,int>m;
        while(n>0){
            int r = n%10;
            m[r]++;
            n/=10;
        }
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>temp;
            int temp_num = nums[i];
            while(temp_num>0){
                int r = temp_num%10;
                temp[r]++;
                temp_num/=10;
            }
            bool same = true;
            if(temp.size()==m.size()){
                for(auto i:m){
                    if(temp.count(i.first)){
                        if(temp[i.first]!=m[i.first]){
                            same = false;
                            break;
                        }
                    }
                    else{
                        same = false;
                        break;
                    }
                }
                if(same){
                    return true;
                }
            }
        }
        return false;
    }
};
