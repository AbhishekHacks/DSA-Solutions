/*Given two matrices mat1[][] and mat2[][] of size n x n, where the elements in each matrix are arranged in strictly ascending order. Specifically, each row is sorted from left to right, and the last element of a row is smaller than the first element of the next row.
You're given a target value x, your task is to find and count all pairs {a, b} such that a is from mat1 and b is from mat2 where the sum of a + b is equal to x.*/

//Time Complexity -- O(n^2)

//User function Template for Java

class Solution {
    int countPairs(int mat1[][], int mat2[][], int n, int x) {
        // code here
        int count=0;
        int i1=0,j1=0,i2=n-1,j2=n-1;
        while(i1<=n-1&&i2>=0){
            if((mat1[i1][j1]+mat2[i2][j2])==x){
                count+=1;
                j1+=1;
                j2-=1;
                if(j1==n){
                    j1=0;
                    i1+=1;
                }
                if(j2==-1){
                    j2=n-1;
                    i2-=1;
                }
            }
            else if((mat1[i1][j1]+mat2[i2][j2])<x){
                if(j1==n-1){
                    i1+=1;
                    j1=0;
                }
                else{
                    j1+=1;
                }
            }
            else{
                if(j2==0){
                    i2-=1;
                    j2=n-1;
                }
                else{
                    j2-=1;
                }
            }
        }
        return count;
    }
}
