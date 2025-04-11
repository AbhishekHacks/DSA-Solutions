/*'N' friends are playing together. The wallet balance of each friend is given in an array 'ARR'. In one transaction, a friend who has a wallet balance greater than or equal to Rs. 'K' can give Rs. 'K' to any other friend.

After the transaction, the wallet balance of money taker increases by Rs. 'K', whereas the wallet balance of money giver decreases by Rs. 'K'.

You are given the array containing the wallet balance of each friend and the special number 'K'. Your task is to find the minimum number of transactions needed to make the wallet balance of all the friends the same.

In case if it is not possible to make the wallet balance of all the friends equal, then print -1 in this case.

*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
int minTransactions(int k, vector < int > & arr) {
    // Write your code here.

    int n = arr.size();

    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    int individual = sum/n;
    int transactions1 = 0;
    int transactions2 = 0;

    for(int i=0;i<n;i++){
        if(arr[i]<individual){
            int diff = individual - arr[i];
            if(diff%k!=0){
                return -1;
            }
            transactions1+=(diff/k);
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i]>individual&&arr[i]>=k){
            int diff = arr[i]-individual;
            if(diff%k!=0){
                return -1;
            }
            transactions2+=(diff/k);
        }
    }

    if(transactions1!=transactions2){
        return -1;
    }

    return transactions1;
}
