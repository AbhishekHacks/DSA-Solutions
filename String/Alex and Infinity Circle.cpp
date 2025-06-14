/*Alex wanted to buy a new keyboard, but due to the low battery in his GPS, he had to print his route on paper, now he wants to know if he can return safely to his home following the instructions written by him. The city of Alex can be represented by a 2D plane, and every location is denoted by ('X','Y') coordinates. Alex is currently standing at ( 0, 0 ) facing north.

The printed route contains a string with characters like:

'L' : which denotes he should turn to the left of the direction he is facing.
'R' : which denotes he should turn to the right of the direction he is facing. 
'G' : which denotes he should walk in the same direction by one unit.
Determine whether he can return home safely or not by following his instruction on the printed sheet.

Note:

He can follow the same printed set of instructions as many times as wanted.*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
string isPossible(string str,int n) {
    //	Write your code here. 
    bool north = true;
    bool east = false;
    bool west = false;
    bool south = false;
    int x=0,y=0;
    for(int it=0;it<4;it++){
        for(int i=0;i<n;i++){
            if(north){
                if(str[i]=='G'){
                    y+=1;
                }
                else if(str[i]=='L'){
                    west=true;
                    north=false;
                }
                else{
                    east=true;
                    north=false;
                }
            }
            else if(west){
                if(str[i]=='G'){
                    x-=1;
                }
                else if(str[i]=='L'){
                    south=true;
                    west=false;
                }
                else{
                    north=true;
                    west=false;
                }
            }
            else if(east){
                if(str[i]=='G'){
                    x+=1;
                }
                else if(str[i]=='L'){
                    north=true;
                    east=false;
                }
                else{
                    south=true;
                    east=false;
                }
            }
            else{
                if(str[i]=='G'){
                    y-=1;
                }
                else if(str[i]=='L'){
                    east=true;
                    south=false;
                }
                else{
                    west=true;
                    south=false;
                }
            }
        }
        if(x==0&&y==0){
            return "True";
        }
    }
    return "False";
}
