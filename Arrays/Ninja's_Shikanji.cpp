/*Ninja opened a shikanji’s stall to earn a living for him. In his stall, each shikanji drinks cost ‘5$’. Customers are standing in the form queue and each customer either pays ‘5$, 10$, 20$ ‘ so now Ninja has to give them change so that each customer exactly pays ‘5$’.

So now help the ninja to find out whether he is able to charge exactly ‘5$’ from each customer by providing them the change.

So your task is to write a code to check whether ninja can provide change to the customer if they paid extra to him. You will be provided with the ‘BILL_ARR’ array denoting the amount paid by each customer you have to return ‘True’ if it is possible else you have to return ‘False’.

Example:

Suppose given ‘BILL_ARR’ array is { 5, 5, 5, 10, 20 } so we return ‘True’ for this test case as from first ‘3’ customers we take ‘5$’ from each customer then ‘4th’ customer give ‘10$’ we give him ‘5$’ back now we have ‘2’, ‘5$’ note and ‘1’, ‘10$’ note than ‘5th’ customer give ‘20$’ so we give him back one ‘10$’ and one ‘5$’ note.*/

#include <bits/stdc++.h> 
bool ninjaShikanji(vector<int> bill, int n) {
	// Write your code here.
	int note_5=0;
	int note_10=0;
	int note_20=0;
	for(int i=0;i<n;i++){
		if(bill[i]==5){
			note_5++;
		}
		else if(bill[i]==10){
			note_10++;
			if(note_5<=0){
				return false;
			}
			note_5--;
		}
		else if(bill[i]==20){
			note_20++;
			if(note_10>=1&&note_5>=1){
				note_10--;
				note_5--;
			}
			else if(note_5>=3){
				note_5-=3;
			}
			else{
				return false;
			}
		}
	}
	return true;
}
