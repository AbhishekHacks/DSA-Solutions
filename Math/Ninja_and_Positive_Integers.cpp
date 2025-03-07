/*Ninja likes to play with positive integers. One day he found a positive integer ‘N’ and started to think about 3 positive integers which will sum up to ‘N’ but the LCM of these integers should be less than or equal to ‘N’/2, i.e.,

a1 + a2 + a3 = N
LCM(a1, a2, a3) <= N/2
Since this task is too simple for Ninja, he asked you to find the three numbers satisfying the above conditions.

For Example:
Let N = 4, then we can choose 1, 1, and 2. The sum of these integers is 4 which is equal to ‘N’ and their LCM is 2 which is <= N/2.*/

//Time Complexity -- O(1)

#include <bits/stdc++.h> 
vector<int> positiveIntegers(int n){
    vector<int>v;
    if(n%3==0){
        v.push_back(n/3);
        v.push_back(n/3);
        v.push_back(n/3);
    }
    else{
        if(n%2==0){
            n=n/2;
            if(n%2==0){
                v.push_back(n/2);
                v.push_back(n/2);
                v.push_back(n);
            }
            else{
                v.push_back(2);
                v.push_back(n-1);
                v.push_back(n-1);
            }
        }
        else{
            v.push_back(1);
            v.push_back(n/2);
            v.push_back(n/2);
        }
    }
    return v;
}
