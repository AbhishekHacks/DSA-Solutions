/*You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.*/

//Time Complexity -- (Nlog(N))

class Solution {
public:

    bool isPossible(vector<int>& fruits,int n,int mid){
        unordered_map<int,int>m;
        for(int i=0;i<mid;i++){
            m[fruits[i]]++;
        }
        if(m.size()<=2){
            return true;
        }
        int index = 0;
        for(int i=mid;i<n;i++){
            m[fruits[i]]++;
            m[fruits[index]]--;
            if(m[fruits[index]]==0){
                m.erase(fruits[index]);
            }
            if(m.size()<=2){
                return true;
            }
            index++;
        }
        return false;
    }

    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n<=2){
            return n;
        }
        //binary search
        int start = 2;
        int end = n;
        int answer;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(fruits,n,mid)){
                answer = mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return answer;
    }
};
