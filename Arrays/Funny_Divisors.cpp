/*Ninja is bored with his previous game of numbers, so now he is playing with divisors.

He is given 'N' numbers, and his task is to return the sum of all numbers which is divisible by 2 or 3.

Let the number given to him be - 1, 2, 3, 5, 6. As 2, 3, and 6 is divisible by either 2 or 3 we return 2 + 3 + 6 = 11.

*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
int findSum(int n, vector<int>& arr) {
    // Write your code here

    //store the sum of numbers divisible by 2 or 3
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0||arr[i]%3==0){
            sum+=arr[i];
        }
    }

    //return the sum
    return sum;
}
