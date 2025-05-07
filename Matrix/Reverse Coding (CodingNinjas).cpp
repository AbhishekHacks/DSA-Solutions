/*As a part of its annual techno-cultural fest, NinjaCity will conduct a technical event, Decode, where it has given a matrix, and the participants have to decode it.

The participants are given a N*M matrix; they need to print the rows in reverse order. Do this for every row.

Among the participants, a participant named Ninja is new to programming and doesn’t have much experience; he asks you to solve the problem. Can you help Ninja reverse all the rows in reverse order?*/

//Time Complexity -- O(n*m)

#include <bits/stdc++.h> 
vector<vector<int>> ninjaCity(vector<vector<int>> &mat)
{
    //write your code here
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0;i<n;i++){
        int j1=0;
        int j2=m-1;
        while(j1<j2){
            swap(mat[i][j1],mat[i][j2]);
            j1++;
            j2--;
        }
    }
    return mat;
}
