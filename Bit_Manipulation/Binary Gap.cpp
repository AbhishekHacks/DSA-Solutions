/*It is a day of celebration here at Coding Ninjas because our beloved Ninja Hu-chan is going to get his JatSu belt (the highest belt a ninja can get). He is just one step away from making his dream come true, but hold the line, Hu-chan’s master knows all his weaknesses and is going to do a final test of his skills before he is announced as the greatest ninja ever.

Master is aware of Ninja Hu-chan’s rivalry with maths and therefore he gives him a mathematical problem to solve, being a good friend and well-wisher of our Ninja, can you help him solve the problem assigned and thus acclaim the title of the greatest ninja?

The problem read as follows:

You are given a number ‘NUM’, return the maximum distance between any two adjacent 1s in the binary representation of 'NUM'.

Note:

The two 1s are called adjacent if there isn’t another 1 between them. The distance between 2 bits is the absolute difference between their bit positions.*/

//Time Complexity -- O(log(num))

#include <bits/stdc++.h> 
int binaryGap(int num) {
    // Write your code here.
    int maximum = 0;
    bool mila=false;
    int prev_pos=0;
    int curr_pos=0;
    while(num>0){
        if((num&1)==1&&mila==false){
            prev_pos=curr_pos;
            mila=true;
        }
        else if((num&1)==1){
            maximum = max(maximum,(curr_pos-prev_pos));
            prev_pos=curr_pos;
        }
        num=num>>1;
        curr_pos+=1;
    }
    return maximum;
}
