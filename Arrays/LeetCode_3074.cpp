/*You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int m = capacity.size();
        int sum_apple = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end());
        int sum = 0;
        int count = 0;
        for(int i=m-1;i>=0;i--){
            sum+=capacity[i];
            count++;
            if(sum>=sum_apple){
                break;
            }
        }
        return count;
    }
};
