/*You are given two 0-indexed integer arrays player1 and player2, representing the number of pins that player 1 and player 2 hit in a bowling game, respectively.

The bowling game consists of n turns, and the number of pins in each turn is exactly 10.

Assume a player hits xi pins in the ith turn. The value of the ith turn for the player is:

2xi if the player hits 10 pins in either (i - 1)th or (i - 2)th turn.
Otherwise, it is xi.
The score of the player is the sum of the values of their n turns.

Return

1 if the score of player 1 is more than the score of player 2,
2 if the score of player 2 is more than the score of player 1, and
0 in case of a draw.*/

//Time Complexity -- O(n)

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        int score1=0;
        int score2=0;
        for(int i=0;i<n;i++){
            if(i==0){
                score1+=player1[0];
                score2+=player2[0];
            }
            else if(i==1){
                if(player1[0]==10){
                    score1+=(2*player1[1]);
                }
                else{
                    score1+=player1[1];
                }
                if(player2[0]==10){
                    score2+=(2*player2[1]);
                }
                else{
                    score2+=player2[1];
                }
            }
            else{
                if(player1[i-1]==10||player1[i-2]==10){
                    score1+=(2*player1[i]);
                }
                else{
                    score1+=player1[i];
                }
                if(player2[i-1]==10||player2[i-2]==10){
                    score2+=(2*player2[i]);
                }
                else{
                    score2+=player2[i];
                }
            }
        }
        if(score1==score2){
            return 0;
        }
        if(score1>score2){
            return 1;
        }
        return 2;
    }
};
