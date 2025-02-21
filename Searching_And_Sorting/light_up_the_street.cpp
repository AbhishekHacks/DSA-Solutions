/*You are walking on a street of length ‘N’. You want to light up the street by installing street lights.

There are 'M' streetlights and the 'ith' streetlight can be installed at position 'Ci'.

You are also given the range of the streetlights 'R' which means that the 'ith' streetlight installed at position 'Ci' will enlighten street from 'Ci-R' to 'Ci+R'.

Output the minimum number of street lights required to light up the whole street or output -1 if it is impossible to light the whole street under the given conditions.

It is sufficient to enlighten the integer positions, it is not required to enlighten the area between two integer positions.

For example : 'N' = 8, 'M' = 2, 'C' = [1, 6], 'R' = 2. The answer for this case is 2 as we can enlighten streetlight at position 1 and streetlight at position 6. These two will enlighten the positions 1, 2, 3, 4, 5, 6, 7, 8.

Example:-
N=10, M=3
C = [2,4,7] ( The positions of the streetlights )
R = 3 ( The range of the street-lights)

The answer will be 2 as we can install the first street light at position 2 so it illuminates the street from positions from 1 to 5 and the third street light at 7 so it illuminates the street from positions from 4 to 10.*/

#include <bits/stdc++.h> 

bool isPossible(int n, int m , int k , vector <int> Checkpoints,int mid){
    int totallights=0;
    int pos=1;
    while(pos<=n){
        int maxcoverage=-1;
        for(int i=0;i<m;i++){
            if(Checkpoints[i]-k<=pos&&Checkpoints[i]+k>=pos){
                if(maxcoverage<Checkpoints[i]+k){
                    maxcoverage=Checkpoints[i]+k;
                }
            }
        }
        if(maxcoverage==-1){
            return 0;
        }
        totallights++;
        pos=maxcoverage+1;
    }
    if(totallights>mid){
        return 0;
    }
    return 1;
}

int LightUptheStreet(int n, int m , int k , vector <int> Checkpoints){
    // Write Code here.
    sort(Checkpoints.begin(),Checkpoints.end());
    int start=1;
    int end=m;
    int ans=-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(isPossible(n,m,k,Checkpoints,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
