/*Write a program to increment the valuie of a variable using pointers*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  int num = 5;
  int *ptr = &num;
  (*ptr)++;
  cout<<num;
  return 0;
}

//output --> 6
