/*Chess tournament is going to be organized in Ninjaland. There will be C chess players going to attend the tournament. All the players will be staying in a hotel. The hotel has N free rooms available for the players, where one player will choose one room to live in. The ith room is at position[i] in the hotel. All rooms are in distinct positions.

Focus level of a chess player is defined as the minimum distance between his room and the room of another player. The overall focus of a tournament is defined as the minimum focus level among all players. You as an organizer obviously want the overall focus as high as possible so you assign the rooms to players such that the overall focus is as high as possible.

For example,
let say we have 3 players and 5 rooms available and the rooms are at positions:  1 2 3 4 6
Here the optimal allocation is in rooms 1 3 6 and the overall focus level is 2.*/

//Time Complexity -- O(nlogn)

#include <bits/stdc++.h> 

bool isPossible(vector<int>& positions,int n,int c,int mid){
    int totalplayers=1;
    int prev=positions[0];
    for(int i=1;i<n;i++){   
        int curr = positions[i];
        int distance = curr - prev;
        if(distance>=mid){
            totalplayers++;
            if(totalplayers==c){
                return true;
            }
            prev=curr;
        }
    }
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(),positions.end());
    int start=1;
    int end=positions[n-1]-positions[0];
    int answer=1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(isPossible(positions,n,c,mid)){
            answer=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return answer;
}
