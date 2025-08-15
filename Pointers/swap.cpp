/*Write a program to swap two numbers in c++ using the concept of pointers*/

#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main(){
  int num1 = 5;
  int num2 = 10;
  swap(&num1,&num2);
  cout<<num1<<" "<<num2;
  return 0;
}
