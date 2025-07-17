/*You are given two positive integers x and y, denoting the number of coins with values 75 and 10 respectively.

Alice and Bob are playing a game. Each turn, starting with Alice, the player must pick up coins with a total value 115. If the player is unable to do so, they lose the game.

Return the name of the player who wins the game if both players play optimally.*/

//Time Complexity -- O(min(x,y/4))

class Solution {
public:
    string winningPlayer(int x, int y) {
        string winner="Bob";
        int a=0;
        while(x>=1&&y>=4){
            if(a%2==0){
                winner = "Alice";
            }
            else{
                winner = "Bob";
            }
            x-=1;
            y-=4;
            a++;
        }
        return winner;
    }
};
