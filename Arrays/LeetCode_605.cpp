/*You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.*/

//Time Complexity -- O(n)

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //O(n)
        if(n==0){
            return true;
        }
        int count=0;
        int s = flowerbed.size();
        if(s==1){
            if(flowerbed[0]==0&&n==1){
                return true;
            }
        }
        for(int i=0;i<s;i++){
            if(flowerbed[i]==0){
                if(i==0){
                    if(i+1<s){
                        if(flowerbed[i+1]==0){
                            flowerbed[i]=1;
                            count++;
                            if(count==n){
                                return true;
                            }
                        }
                    }
                }
                else if(i==s-1){
                    if(flowerbed[i-1]==0){
                        flowerbed[i]=1;
                        count++;
                        if(count==n){
                            return true;
                        }
                    }
                }
                else{
                    if(flowerbed[i-1]==0&&flowerbed[i+1]==0){
                        flowerbed[i]=1;
                        count++;
                        if(count==n){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
