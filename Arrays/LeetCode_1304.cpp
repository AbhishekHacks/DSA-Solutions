/*Given an integer n, return any array containing n unique integers such that they add up to 0.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        int start = (-1)*(n/2);
        int end = n/2;
        for(int i=start;i<=end;i++){
            if(n%2==0){
                if(i!=0){
                    ans.push_back(i);
                }
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};
