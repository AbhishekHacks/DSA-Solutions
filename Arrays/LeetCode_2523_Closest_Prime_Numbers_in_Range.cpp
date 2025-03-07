/*Given two positive integers left and right, find the two integers num1 and num2 such that:
left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].*/

//Time Complexity -- O(Nlog(log(N))) using Seive of eratosthenes

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(left==right){
            vector<int>v;
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }

        //seive of eratosthenes

        vector<bool>prime(right+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<prime.size();i++){
            int mult=2;
            while((i*mult)<=right){
                prime[(i*mult)]=false;
                mult++;
            }
        }

        int num1=0;
        int num2=0;
        int i=left;
        int min=INT_MAX;
        vector<int>v={-1,-1};
        while(i<right){
            if(prime[i]==true){
                int j=i+1;
                while(j<=right){
                    if(prime[j]==true){
                        int diff=(j-i);
                        if(min>diff){
                            min=diff;
                            v.clear();
                            v.push_back(i);
                            v.push_back(j);
                        }
                        break;
                    }
                    j++;
                }
                i=j;
            }
            else{
                i++;
            }
        }
        return v;
    }
};
