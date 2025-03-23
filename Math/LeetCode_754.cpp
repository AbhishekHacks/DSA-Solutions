/*You are standing at position 0 on an infinite number line. There is a destination at position target.

You can make some number of moves numMoves so that:

On each move, you can either go left or right.
During the ith move (starting from i == 1 to i == numMoves), you take i steps in the chosen direction.
Given the integer target, return the minimum number of moves required (i.e., the minimum numMoves) to reach the destination.

*/

//Time Complexity -- O(sqrt(target))

class Solution {
public:
    int reachNumber(int target) {

        //take the absolute value of target
        target=abs(target);
        
        //initialise two variables n and sum
        int n=0;
        int sum=0;

        //calulate the sum of elements starting from 1 until sum>=target
        while(sum<target){
            n++;
            sum+=n;
        }

        //check if the difference of sum and target is even
        if((sum-target)%2==0){
            //if yes return n
            return n;
        }

        //if not keep on incrementing n until sum - target is even
        else{
            while((sum-target)%2!=0){
                n++;
                sum+=n;
            }

            //finally return n when even difference
            return n;
        }
    }
};
